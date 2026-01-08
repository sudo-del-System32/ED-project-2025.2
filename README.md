# ED-project-2025.2



## Bem-vindos ao Organize as garrafas! Um jogo desenvolvido em C para a disciplina de Estrutura de Dados!

<img width="979" height="263" alt="image" src="https://github.com/user-attachments/assets/a0bcebaa-2931-4f3a-b598-49d186d8c92b" />

## 🎮 COMO JOGAR: 

- Ao iniciar o jogo, você podera escolher quantas garrafas ira ter que organizar!
- Então elas apareceram e você terá que digitar o numero da garrafa de origem junto de seu destino, ex: 12 (ira tirar a primeira cor da garrafa 1 e colocar na garrafa 2).
- Organize todas as garrafas para vencer!
- ATENÇÃO: Se divirta!


  

## 🖥️ COMO COMPILAR O CODIGO E EXECUTAR O JOGO: 

Use o seguinte codigo em seu terminal, para executar e compilar o jogo:

```

mkdir -p temp

find . -name "*.c" -exec sh -c 'gcc -c "$1" -o "temp/$(basename "${1%.c}.o")"' _ {} \;

gcc temp/*.o -o ./main.exe

./main.exe

```




## 👾 JOGUE AQUI:

https://onlinegdb.com/VjFkaqVv0

## 📌 COLABORADORES:

✦ [Leticia Gomes](https://github.com/mareshbard)

✦ [Cadu](https://github.com/Mordegb)

✦ [Daniel Bertini](https://github.com/sudo-del-System32)
