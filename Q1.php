<?php
$xml = simplexml_load_file("book.xml") or die("Error: Cannot create object");
echo "<h1 align=center> Books Information </h1>";
echo "<table border=2>";
echo "<tr> <th> Book Category </th>
 <th> Book Language </th>
 <th> Book Title </th>
 <th> Book Author </th>
 <th> Book Year </th>
 <th> Book Price </th>
 </tr>";
foreach ($xml->children() as $books) {
    $category = $books['category'];
    $language = $books->title['lang'];

    echo "<tr> <td>$category </td>
 <td>$language </td>
 <td>$books->title </td>
 <td>$books->author </td>
 <td>$books->year </td>
 <td>$books->price</td>
 </tr>";
}
