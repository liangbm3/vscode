STACK	SEGMENT  PARA  'STACK'				;定义堆栈段，段名为 STACK（可以取其他的）
		DB 100 DUP('?')						;分配堆栈的大小，设置为100字节，以？填充
STACK	ENDS								;堆栈段结束
DATA	SEGMENT								;定义数据段，段名为 DATA （可以取其他的）
  		STRING	DB 'HELLO!','$'				;定义字符串数据
DATA	ENDS
CODE	SEGMENT								;定义代码段，段名为 CODE （可以取其他的）
		ASSUME CS:CODE, DS:DATA, SS:STACK	;特别重要，将 CS、DS、SS 指向定义的段
START:	MOV  AX,  DATA						;程序开始的地方
		MOV  DS,  AX
		MOV  AX,  STACK
		MOV  SS,  AX
		LEA  DX,  STRING
		MOV  AH, 09H
		INT  21H
		MOV  AH,  4CH
		INT  21H
CODE  	ENDS						
		END START 							;程序结束的地方
