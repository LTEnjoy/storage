assume cs:code,ds:display,ss:stack
stack segment
	dw 10 dup(0)
stack ends

data segment
	db 10 dup(0)
data ends

judge segment
	true db 0
judge ends

search segment
	db 10 dup(0)
	line db 10
	wrong db"NOT    FOUNDOUT",0
search ends

storage segment
	s1 db 9 dup ('*'),0 ;学生学号
	   db 9 dup ('*'),0 ;学生成绩
	   db 9 dup ('*'),0 ;学生排名
	s2 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	s3 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	s4 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	s5 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	s6 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	s7 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	s8 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	s9 db 9 dup ('*'),0 
	   db 9 dup ('*'),0 
	   db 9 dup ('*'),0     
	s dw s1,s2,s3,s4,s5,s6,s7,s8,s9
	point dw 0
storage ends

display segment
	d1 db "Input A Number To Make A Choice",0
	d2 db "1.Input Student's Grades",0
	d3 db "2.Inquire A Student's Grades",0
	d4 db ">>Press 'q' To Quit",0
	d5 db "ID:",0
	d6 db "Score:",0
	d7 db "Rank:",0
	d8 db ">>Press 'ESC' To Return",0
	d9 db ">>Press 'Enter' To Finish",0
	d10 db "Input A Student's ID:",0
	d11 db "You Can Still Input   Of Student's Information",0
	d12 db 0,0
	d13 db "ID       Score      Rank",0
	d14 db 7,9,11
	show dw d5,d6,d7
display ends

code segment
	db 0
start:
		mov ax,stack
		mov ss,ax
		mov sp,20
start0:
		call screenClean ;清屏
		mov ax,search
		mov ds,ax
		mov line,10
		mov ax,display
		mov ds,ax
		mov dh,6	;确定输出字符串的行列颜色
		mov	dl,25 
		mov cl,2
		mov si,offset d1
		call showStr
		
		mov dh,7
		mov	dl,25 
		mov cl,2
		mov si,offset d2
		call showStr
		
		mov dh,8
		mov	dl,25 
		mov cl,2
		mov si,offset d3
		call showStr
		
		mov dh,12
		mov	dl,50 
		mov cl,2
		mov si,offset d4
		call showStr
		
		call checkInput ;获取用户选项保存在al中
		cmp al,1
		je inputGrades0
		
		cmp al,2
		je Inquire
		jmp start0
	inputGrades0:
		jmp inputGrades
			;查询学生信息
	Inquire:
		mov ah,2  ;设置光标
		mov bh,0
		mov dh,7
		mov dl,25
		int 10h
		mov dh,7
		call lineClean
		mov si,0
		mov ax,display
		mov ds,ax
		mov dh,9
		mov dl,25
		mov cl,2
		mov di,si
		mov si,offset d13
		call showStr
		mov dh,7
		mov dl,25
		mov cl,2
		mov si,0
		mov ax,data
		mov ds,ax
		call getstr
		
		mov ax,search
		mov ds,ax
		mov dh,line
		mov dl,25
		mov cl,2
		mov si,0
		call showStr
		
		mov ax,storage
		mov ds,ax
		mov ax,search
		mov es,ax
		mov di,0
		mov si,s
		mov cx,9
	check:				;检查学生学号是否存在	
		push cx
		mov cx,9
		mov bx,0
	still:	
		mov ax,es:[di]
		cmp ax,[si][bx]
		jne next
		inc di
		inc bx
		loop still
		jmp  result
	next:
		add si,30
		pop cx
		mov di,0
		loop check
		jmp noResult
	result:
		mov dl,25
		mov di,si
		mov cx,3
		mov ax,search
		mov ds,ax
		mov dh,line
		inc line
	print:
		push cx
		mov ax,storage
		mov ds,ax
		mov cl,2
		mov si,di
		call showStr
		add di,10
		add dl,10
		pop cx
		loop print
		jmp Inquire
	noResult:
		mov ax,search
		mov ds,ax
		mov dh,line
		inc line
		mov dl,35
		mov cl,2
		mov si,offset wrong
		call showStr
		jmp Inquire
		
	reset:
		mov dh,7
		call lineClean
		mov dh,9
		call lineClean
		mov dh,11
		call lineClean
		jmp continue	
	;输入学生成绩
	inputGrades:
		
		mov dh,6
		call lineClean
		
		mov ax,storage ;根据保存的数据情况提示用户输入相应类型的数据
		mov ds,ax
		mov ax,point
		mov bx,10
		div bl
		mov ah,0
		mov bx,3
		div bl
		mov bl,ah
		cmp bx,0
		push bx
		je reset
		
	continue:	
		mov si,point
		mov ax,290
		sub ax,si
		mov dx,30
		div dl
		add al,30h
		mov dl,al
		mov ax,display
		mov ds,ax
		mov d12,dl
		
		mov si,offset d5
		mov dh,6
		mov	dl,25 
		mov cl,2
		call showStr
		
		mov si,offset d6
		mov dh,8
		mov	dl,25 
		mov cl,2
		call showStr
		
		mov si,offset d7
		mov dh,10
		mov	dl,25 
		mov cl,2
		call showStr
		
		mov dh,5
		mov	dl,25 
		mov cl,2
		mov si,offset d11
		call showStr
		
		mov dh,5
		mov	dl,45
		mov cl,2
		mov si,offset d12
		call showStr
		
		mov ah,2  ;设置光标
		mov cl,2
		mov bh,0
		pop bx
		mov dh,d14[bx]
		mov cs:[0],dh
		mov dl,25
		int 10h
		
		
		mov si,0
		mov dh,d14[bx]
		mov dl,25
		mov ax,data
		mov ds,ax
		call getstr
		mov ax,judge
		mov ds,ax
		mov true,0
		jmp start0
	
	;打印字符
	showStr:
		push cx
		push ax
		push es
		push bx
		push di
		push ds
		push dx
		mov ax,0b800h
		mov es,ax
		mov al,160
		mul dh
		mov bx,ax
		mov al,2
		mul dl
		mov di,ax
		mov dl,cl
	lp:	
		mov ch,0
		mov cl,[si]
		jcxz ok
		mov byte ptr es:[bx][di],cl
		inc di
		mov es:[bx][di],dl
		inc di
		inc si
		jmp short lp
	ok:
		pop dx
		pop ds
		pop di
		pop bx
		pop es
		pop ax
		pop cx
		ret
	
	;检测用户按键
	checkInput:
		mov ah,0
		int 16h
		cmp ah,10h
		je	quit
		cmp al,31h
		je one
		cmp al,32h
		je two
		jmp checkInput
	one:
		call screenClean
	
		mov dh,12
		mov	dl,50
		mov cl,2
		mov si,offset d4
		call showStr
		
		mov dh,13
		mov	dl,50
		mov cl,2
		mov si,offset d8
		call showStr
		
		mov dh,14
		mov	dl,50
		mov cl,2
		mov si,offset d9
		call showStr
		mov ax,judge
		mov ds,ax
		mov true,1
		mov al,1
		ret
	
	two:
		call screenClean
		
		mov dh,6
		mov	dl,25 
		mov cl,2
		mov si,offset d10
		call showStr
		
		mov dh,12
		mov	dl,50
		mov cl,2
		mov si,offset d4
		call showStr
		
		mov dh,13
		mov	dl,50
		mov cl,2
		mov si,offset d8
		call showStr
		mov al,2
		ret
	quit: 
		mov ax,4c00h
		int 21h
	;用户输入字符串
	getstr:
		push ax
	getstrs:
		mov ah,0
		int 16h
		cmp ah,10h
		je quit
		cmp al,20h
		jb nochar
		mov ah,0
		call charStack

		mov ah,2
		call charStack
		jmp getstrs
		
	nochar:
		cmp ah,0eh
		je backspace
		cmp ah,1ch
		je enter
		cmp ah,01h
		je E0
		jmp getstrs
		E0:	jmp E
	backspace:
		mov ah,1
		call charStack
		mov ah,2
		call charStack
		jmp getstrs
		
	charStack:
		jmp charStart
		table dw charPush,charPop,charShow
		top dw 0	

	enter:
		mov ax,judge
		mov ds,ax
		cmp true,0
		je p0
		mov ax,storage
		mov es,ax
		mov ds,ax
		mov di,point
		cmp di,270
		je p
		add point,10
		mov ax,data
		mov ds,ax
		mov si,0
		mov cx,9
		cld
		rep movsb
	p:	
		mov ax,data
		mov si,0
		mov cx,9
	renew:
		mov byte ptr [si],0
		inc si
		loop renew
		mov word ptr top,0
		pop ax
		pop bx
		jmp inputGrades
	p0: 
		mov ax,search
		mov es,ax
		mov di,0
		mov ax,data
		mov ds,ax
		mov si,0
		mov cx,9
		cld
		rep movsb
		mov ax,data
		mov si,0
		mov cx,9
	renew0:
		mov byte ptr [si],0
		inc si
		loop renew0
		mov word ptr top,0
		pop ax
		ret
		
	E:	
		pop ax
		mov word ptr top,0
		mov ax,judge
		mov ds,ax
		cmp true,0
		je then
		ret
	then:
		pop bx
		jmp start0
	charStart:
		push bx
		push dx
		push di
		push es
		cmp ah,2
		ja sret0
		mov bl,ah
		mov bh,0
		add bx,bx
		jmp word ptr table[bx]
	sret0:	jmp sret
	charPush:
		cmp top,9
		je sret
		mov bx,top
		mov [si][bx],al
		inc top
		jmp sret
	
	charPop:
		cmp top,0
		je sret
		dec top
		mov bx,top
		mov al,0
		mov [si][bx],al
		jmp sret
		
	charShow:
		mov bx,0b800h
		mov es,bx
		mov al,160
		mov ah,0
		mul dh
		mov di,ax
		add dl,dl
		mov dh,0
		add di,dx
		
		mov bx,0
	
	charShows:
		cmp bx,top
		jne noEmpty
		mov byte ptr es:[di],' '
		mov ah,2  ;设置光标
		mov bh,0
		mov dh,cs:[0]
		mov dl,25
		mov cl,2
		add dl,bl
		int 10h
		jmp sret
	
	noEmpty:
		mov al,[si][bx]
		mov es:[di],al
		mov byte ptr es:[di+1],2
		inc bx
		add di,2
		jmp charShows
	sret:
		pop es
		pop di
		pop dx
		pop bx
		ret
		
		
		;清空屏幕
	screenClean:
		push bx
		push cx
		push es
		mov bx,0b800h
		mov es,bx
		mov bx,0
		mov cx,2000
	screenCleanLoop:
		mov byte ptr es:[bx],' '
		add bx,2
		loop screenCleanLoop
		pop es
		pop cx
		pop bx
		ret
	
	lineClean:
		push bx
		push cx
		push es
		push ax
		mov bx,0b800h
		mov es,bx
		mov ah,160
		mov al,dh
		mul ah
		mov bx,ax
		mov cx,80
	lineCleanLoop:
		mov byte ptr es:[bx],' '
		add bx,2
		loop lineCleanLoop
		pop ax
		pop es
		pop cx
		pop bx
		ret
	
code ends
end start
	