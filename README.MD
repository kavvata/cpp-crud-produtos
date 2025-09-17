# Como compilar?

## Instalação de dependências

É necessário ter pelo menos:

- Qt 5.12.
- cmake 4.0.0.

### Windows

Instale o Qt a partir do [site oficial](https://www.qt.io/download).

### Linux

Exemplos para Ubuntu 20.04. Para outra versão ou distribuição, consulte a [Qt Wiki](https://wiki.qt.io/Main).

```shell
sudo apt install build-essential qt5-default qttools5-dev-tools
```

### Outros sistemas

Consulte a [Qt Wiki](https://wiki.qt.io/Main).

## Compilação

Inicialize os submódulos:

```shell
git submodule update --init
```

A partir da pasta do código-fonte, execute:

```shell
cmake -S. -Bbuild
cmake --build build
```
