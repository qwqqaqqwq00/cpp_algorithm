data segment use16
num db 11h,22h,33h,44h
len equ len-num
data ends

start:
    mov ax,num
    mov eax,dword ptr num
    mov si, offset num
    add 2[si],len
    mov byte ptr 2[si],'A'

    inc [si]
    dec byte ptr [si]