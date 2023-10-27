<!-- Q5. Write a program to read one file and display the contents of the file with its size. -->
<?php
echo "<h2>Contents of the file \"php.txt\" : </h2>";
echo "<h3>\"";
readfile("file.txt");
echo "\"</h3>";

$f = fopen("file.txt", "r");
echo "<h3>Size of file is " . fstat($f)[7] . " Bytes.</h3>";