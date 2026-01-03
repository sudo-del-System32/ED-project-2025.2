# ED-project-2025.2

  

Use o seguinte codigo em seu terminal, para executar e compilar a tarefa:

```

mkdir -p temp

find . -name "*.c" -exec sh -c 'gcc -c "$1" -o "temp/$(basename "${1%.c}.o")"' _ {} \;

gcc temp/*.o -o ./main.exe

./main.exe

```

Acesse o jogo sem instalar usando o online gdb no link abaixo:
https://onlinegdb.com/VjFkaqVv0
