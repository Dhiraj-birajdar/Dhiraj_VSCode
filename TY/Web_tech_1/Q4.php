<!-- Q4 create your array of 30 high temperatures, approximating the weather for a spring month, then find the average high temp, the five warmest high temps and the five coolest high temps. display the result on the browser.-->
<?php
$temp = array(
    25, 27, 29, 29, 30, 30, 32, 31, 31, 32,
    30, 31, 32, 33, 33, 31, 30, 32, 30, 31,
    32, 32, 33, 33, 33, 34, 35, 37, 36, 38);

$avg_temp = (int)(array_sum($temp)/30);
$temp = array_unique($temp);
rsort($temp);
echo "<center><h2>Average high Temperature is $avg_temp&deg</h2>";
echo "<h2>The five warmest high temperatures are : ";
for ($i = 0; $i < 5; $i++)
    echo $temp[$i]."&deg  ";
echo "</h2>";
sort($temp);
echo "<h2>The five coolest high temperatures are : ";
for ($i = 0; $i < 5; $i++)
    echo $temp[$i]."&deg  ";
echo "</h2></center>";