org 00h
mov r5,40h
mov r0,#42h
mov a,@r0
again : inc r0
mov 41h,@r0
cjne a,41h,chk
sjmp quit
chk : jc again
mov a,41h
quit : djnz r5,again
mov r7,a
end


	org 00h
	mov a,#63h ; input  hex no21
	mov b,#100
	div ab
	mov r1,a
	mov a,b
	mov b,#10
	div ab
	mov r1,a
	mov r2,b
	end  