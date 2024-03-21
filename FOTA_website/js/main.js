   // Function to make an AJAX request to read the file and update HTML
   function readFileAndUpdateHTML() {
    // Create a new XMLHttpRequest object
    var xhr = new XMLHttpRequest();

    // Specify the URL of the file to be read
    var url = 'http://naavi.mypressonline.com//PublishedData//Doors_open//file.txt'; // Replace 'example.txt' with the actual path to your file

    // Configure the AJAX request
    xhr.open('GET', url, true);

    // Define the function to handle the AJAX response
    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            // Update the HTML with the contents of the file
            document.getElementById('fileContent').innerHTML = xhr.responseText;
        }
    };

    // Send the AJAX request
    xhr.send();
}

// Call the function to read the file and update HTML when the page loads
window.onload = readFileAndUpdateHTML;

