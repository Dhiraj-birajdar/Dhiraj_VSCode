// arrow function
let star = (n) => {
    let s = "";
    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= i; j++) {
            s += " *";
        }
        s += "<br>";
    }
    return s;
}

// nameless function
let update = function () {

    let n = document.getElementById("fname").value;
    document.getElementById("op").innerHTML = star(parseInt(n));
}

// normal function
function change() {

}

// light and dark mode toggle
let light = true;
let but = document.querySelector("button");
but.addEventListener("click", () => {
    let page = document.querySelector("body");
    if (light) {
        page.style.backgroundColor = "#292c35";
        page.style.color = "yellow";
        light = false;
    } else {
        page.style.backgroundColor = "#ffffff";
        page.style.color = "black";
        light = true;
    }
});