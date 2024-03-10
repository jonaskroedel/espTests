document.getElementById('positionSlider').oninput = function() {
    document.getElementById('positionValue').textContent = this.value;
}

document.getElementById('moveServo').addEventListener('click', function() {
    const position = document.getElementById('positionSlider').value;
    const returnPosition = 0; // Fest auf 0 gesetzt
    fetch(`/move-servo?position=${position}&returnPosition=${returnPosition}`)
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.text();
        })
        .then(data => console.log(data))
        .catch(error => console.error('There has been a problem with your fetch operation:', error));
});

// Funktion, um die Temperatur zu aktualisieren
function updateTemperature() {
    fetch('/get-temperature')
        .then(response => response.text())
        .then(temperature => {
            document.getElementById('temperature').textContent = temperature;
        })
        .catch(error => console.error('Fehler beim Abrufen der Temperatur:', error));
}

document.getElementById('setColor').addEventListener('click', function() {
    const color = document.getElementById('colorPicker').value;
    // Entferne das '#' aus dem Hex-Code, da es für die Anfrage nicht benötigt wird
    const hexColor = color.substring(1);
    fetch(`/set-rgb?color=${hexColor}`)
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            console.log("LED-Farbe gesetzt zu:", color);
        })
        .catch(error => console.error('Fehler beim Setzen der LED-Farbe:', error));
});


// Aktualisiere die Temperatur beim Laden der Seite
updateTemperature();

// Setze ein Intervall, um die Temperatur alle 5 Sekunden zu aktualisieren
setInterval(updateTemperature, 500);