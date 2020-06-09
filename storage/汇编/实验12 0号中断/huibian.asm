assume cs:code 
	
code segment
start:	
		mov di,200h
		mov ax,0
		mov es,ax
		mov si, offset do
		mov es:[0],di
		mov es:[2],ax
		mov ax,cs
		mov ds,ax
		cld
		mov cx, offset doEnd - offset do
		rep movsb
		
		mov ax,4c00h
		int 21h
		
do:
		jmp doStart
		db"divide error!",0

doStart:	
		mov dh,12
		mov dl,35
		mov cl,2
		mov si,203h
		call show_str
		
		mov ax,4c00h
		int 21h
	show_str:	
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
		mov cl,cs:[si]
		jcxz ok
		mov byte ptr es:[bx][di],cl
		inc di
		mov es:[bx][di],dl
		inc di
		inc si
		jmp short lp
	ok:
		ret
doEnd:
		nop
code ends
end start