import turtle as t
from random import randint as r

def shape(side):
    for _ in range(side):
        t.right(int(360/side))
        t.fd(100)

t.colormode(255)
t.speed(0)
t.hideturtle()
t.bgcolor(0, 0, 0)

for i in range(int(360/10)):
    t.color(r(0, 255), r(0, 255), r(0, 255))
    t.pensize(2)
    t.circle(100)
    # t.circle(150)
    # shape(5)
    shape(8)
    t.setheading(t.heading() + 10)

t.exitonclick()