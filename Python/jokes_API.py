import requests
import turtle

s = turtle.Screen()
a = turtle.Turtle("turtle")
# a.hideturtle()
# a.penup()


def get_joke():
    """
    It gets a joke from the jokeapi.dev website, and then prints it out
    """
    try:
        response = requests.get("https://v2.jokeapi.dev/joke/Any?category=programming")
        j = response.json()
        a.goto(x=-300, y=250)
        a.write(j['joke'], font=("comic sans", 20, "normal"))
    except KeyError:
        print("1")
        get_joke()
    else:
        s.exitonclick()


get_joke()