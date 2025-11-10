/* --------------------------------------------------------------
   GLOBAL SETUP
   -------------------------------------------------------------- */
const canvas = document.getElementById('planetCanvas');
const ctx = canvas.getContext('2d');
const container = document.querySelector('.container');

const img = new Image();
img.src = 'https://upload.wikimedia.org/wikipedia/commons/9/94/Pluto-transparent.png';

/* --------------------------------------------------------------
   DRAW BACKGROUND + STARS (once)
   -------------------------------------------------------------- */
function drawStars() {
  ctx.fillStyle = '#000';
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  const starColors = ['#F6F6DC', '#FFF4CF', '#D9FADA', '#ffffff'];
  for (let i = 0; i < 500; i++) {
    const x = Math.random() * canvas.width;
    const y = Math.random() * canvas.height;
    const c = starColors[Math.floor(Math.random() * starColors.length)];
    ctx.fillStyle = c;
    ctx.beginPath();
    ctx.arc(x, y, Math.random() * 1.2 + 0.3, 0, Math.PI * 2);
    ctx.fill();
  }
}

/* --------------------------------------------------------------
   COMET CLASS
   -------------------------------------------------------------- */
class Comet {
  constructor(startX, startY, velX, velY) {
    this.x = startX;
    this.y = startY;
    this.vx = velX;
    this.vy = velY;

    // tail history (max 60 points = ~1 second at 60 fps)
    this.tail = [];
    this.maxTail = 60;
  }

  update() {
    // store current position for the tail
    this.tail.push({ x: this.x, y: this.y });
    if (this.tail.length > this.maxTail) this.tail.shift();

    // move head
    this.x += this.vx;
    this.y += this.vy;
  }

  draw() {
    // ----- TAIL (fades from bright red → transparent) -----
    const grad = ctx.createLinearGradient(
      this.tail[0]?.x ?? this.x,
      this.tail[0]?.y ?? this.y,
      this.x,
      this.y
    );
    for (let i = 0; i < this.tail.length; i++) {
      const ratio = i / this.tail.length;
      grad.addColorStop(ratio, `rgba(255,100,0,${ratio * 0.8})`);
    }
    ctx.strokeStyle = grad;
    ctx.lineWidth = 4;
    ctx.lineCap = 'round';
    ctx.beginPath();
    this.tail.forEach((p, i) => i === 0 ? ctx.moveTo(p.x, p.y) : ctx.lineTo(p.x, p.y));
    ctx.stroke();

    // ----- HEAD (glowing white core + orange halo) -----
    const headGrad = ctx.createRadialGradient(this.x, this.y, 0, this.x, this.y, 12);
    headGrad.addColorStop(0, '#ffffff');
    headGrad.addColorStop(0.4, '#ffaa00');
    headGrad.addColorStop(1, 'rgba(255,150,0,0)');
    ctx.fillStyle = headGrad;
    ctx.beginPath();
    ctx.arc(this.x, this.y, 12, 0, Math.PI * 2);
    ctx.fill();
  }

  isOffScreen() {
    const margin = 100;
    return (
      this.x < -margin ||
      this.x > canvas.width + margin ||
      this.y < -margin ||
      this.y > canvas.height + margin
    );
  }
}

/* --------------------------------------------------------------
   ANIMATION LOOP
   -------------------------------------------------------------- */
let comet = null;
let animId = null;

function animate() {
  // 1. stars (already drawn – we only clear the comet area)
  // 2. draw comet
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  drawStars();          // static background
  if (comet) comet.draw();

  // 3. planet (drawn **after** comet → in front)
  ctx.drawImage(img, 220, 120, 160, 160);

  // update comet
  if (comet) {
    comet.update();
    if (comet.isOffScreen()) {
      cancelAnimationFrame(animId);
      comet = null;
    } else {
      animId = requestAnimationFrame(animate);
    }
  }
}

/* --------------------------------------------------------------
   BUTTON HANDLER – creates a comet with the right direction
   -------------------------------------------------------------- */
function renderComet(num) {
  // stop any previous animation
  if (animId) cancelAnimationFrame(animId);
  comet = null;

  const w = canvas.width;
  const h = canvas.height;
  let startX, startY, vx, vy;

  // speed (feel free to tweak)
  const speed = 3.5;

  switch (num) {
    case 1: // bottom-right → bottom-left (actually top-left → bottom-right)
      startX = -40; startY = -20;
      vx = speed;   vy = speed * 0.67;
      break;
    case 2: // top-right → bottom-left
      startX = w + 40; startY = -20;
      vx = -speed;  vy = speed * 0.67;
      break;
    case 3: // bottom-left → top-right
      startX = -20; startY = h + 40;
      vx = speed;   vy = -speed * 0.67;
      break;
    case 4: // bottom-right → top-left
      startX = w + 20; startY = h + 20;
      vx = -speed;  vy = -speed * 0.67;
      break;
  }

  comet = new Comet(startX, startY, vx, vy);
  animId = requestAnimationFrame(animate);
}

/* --------------------------------------------------------------
   INITIAL DRAW (stars + planet)
   -------------------------------------------------------------- */
img.onload = () => {
  drawStars();
  ctx.drawImage(img, 220, 120, 160, 160);
};