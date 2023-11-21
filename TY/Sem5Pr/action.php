<?php

$str = $_POST["txt"];
$seperator = $_POST["separator"];

echo "<h1>{ explode($separator,$str) }</h1>";
echo "<h1>{ end($str)}</h1>";

echo "<a href=\"Q1.php\"> <button>Back</button></a>";