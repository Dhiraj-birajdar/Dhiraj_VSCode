<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q1</title>
</head>

<body>
    <fieldset>
        <legend>
            <h1>String Operations</h1>
        </legend>
        <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
            <label for="inputString">Enter a string:</label>
            <input type="text" name="inputString"><br><br>

            <label for="separator">Choose a separator:</label>
            <select name="separator">
                <option value="#">#</option>
                <option value="|">|</option>
                <option value="%">%</option>
                <option value="@">@</option>
                <option value="!">!</option>
                <option value=",">,</option>
            </select><br><br>
            <input type="submit" value="Submit">
        </form>
    </fieldset>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $inputString = $_POST["inputString"];
        $separator = $_POST["separator"];

        echo "<h2>Results:</h2>";

        $words = explode($separator, $inputString);
        echo "Split words: " . implode(", ", $words) . "<br><br>";

        $newSeparator = "*";
        $newString = str_replace($separator, $newSeparator, $inputString);
        echo "String with replaced separator: " . $newString . "<br><br>";

        $lastWord = end($words);
        echo "Last word in the string: " . $lastWord . "<br><br>";
    }
    ?>
</body>

</html>