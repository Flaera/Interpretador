# Interpretador

Interpretador desenvolvido na disciplina de Compiladores do período letivo de 2023.1 na Ufal - Campus A. C. Simões como componente curricular para a mesma disciplina.


## Compilar e executar em Linux

Para compilar em distribuições Linux, como Ubuntu, deve executar o comando:

```bash
g++ pynho.cpp -o pynho -Wall
```

Para executar em distribuições Linux, como Ubuntu, deve executar o comando sem as aspas e com o nome do arquivo entre as aspas:

```bash
./pynho <"arquivo_do_programa.txt"
```

## Compilar e executar em Windows

Para compilar em Windows precisará ter o MinGW instalado e as variáveis de ambiente configuradas. Após isso, pode executar o comando abaixo para compilar:

```bash
g++ pynho.cpp -o pynho -Wall
```

E para executar em Windows pode executar o seguinte comando:

```bash
pynho.exe <"arquivo_do_programa.txt"
```
