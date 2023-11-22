<?php
$string=$_POST['str1'];
$seprtaor=$_POST['separator'];
echo "String is $string and separator is $seprtaor <br> <br>";
echo "Split the string into separate words using the given separator. <br> <br>";
$splitwords=explode($seprtaor,$string);
print_r($splitwords);
echo "<br> <br>";
echo "Replace all the occurrences of separator in the given string with some other 
separator.<br> <br> ";
echo str_replace( "$seprtaor", "$", $string );
echo "<br><br><br>";
echo "Find the last word in the given string. <br> <br>";
$split = explode(" ", $string);
$lastWord = $split[count($split)-1];
var_dump($lastWord)
?>
