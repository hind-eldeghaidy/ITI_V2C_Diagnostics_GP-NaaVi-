<?php


$tempFilePath = $_FILES["file"]["tmp_name"];

$homepage = file_get_contents($tempFilePath);
file_put_contents("file.hex",$homepage);
header("Location: index.html");

$file_path = 'PublishedData/Doors_open/file.txt'; // Specify the path to your file

// Check if the file exists
if (file_exists($file_path)) {
    // Read the contents of the file
    $contents = file_get_contents($file_path);
    
    // Output the contents
    echo $contents;
} else {
    echo "File not found";
}
?>

