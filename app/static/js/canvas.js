$(document).ready(function() {

    $('#guessButton').on('click', sendDrawing);
    $('#clearButton').on('click', clearCanvas);

    const canvas = document.getElementById('drawingCanvas');
    const context = canvas.getContext('2d');

    let isDrawing = false;

    canvas.addEventListener('mousedown', startDrawing);
    canvas.addEventListener('mousemove', draw);
    canvas.addEventListener('mouseup', stopDrawing);
    canvas.addEventListener('mouseout', stopDrawing);

    function startDrawing(e) {
        isDrawing = true;
        draw(e);
    }

    function draw(e) {
        if (!isDrawing) return;

        context.lineWidth = 5;
        context.lineCap = 'round';
        context.strokeStyle = '#000';

        context.lineTo(e.clientX - canvas.offsetLeft, e.clientY - canvas.offsetTop);
        context.stroke();
        context.beginPath();
        context.moveTo(e.clientX - canvas.offsetLeft, e.clientY - canvas.offsetTop);
    }

    function stopDrawing() {
        isDrawing = false;
        context.beginPath();
    }

    function sendDrawing() {
        const imageData = canvas.toDataURL();
        baseURL = "API.predict";

        $.ajax({
            type: 'POST',
            url: baseURL,
            contentType: 'application/json',
            data: JSON.stringify({ image: imageData }),
            success: function(guess) {
                alert('AI Guess: ' + guess);
            },
            error: function(error) {
                console.error('Error sending drawing:', error);
            }
        });
    }

    function clearCanvas()
    {
        context.clearRect(0,0, canvas.width, canvas.height);
    }

});