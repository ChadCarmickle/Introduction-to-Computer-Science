window.onload = function() {
    const canvas = document.getElementById('planetCanvas');
    const ctx = canvas.getContext('2d');

    const img = new Image(); // Create a new image object
    img.src = 'https://upload.wikimedia.org/wikipedia/commons/9/94/Pluto-transparent.png'; 

    img.onload = function() {
        // Draw the image when loaded
        ctx.clearRect(0, 0, canvas.width, canvas.height); // Clear before drawing
        ctx.drawImage(img, 120, 120, 160, 160); // Draw the image at x:120, y:120, with width and height of 160
    };
};