**Генерация лексера и парсера**

```bash
antlr4 -v 4.10 -Dlanguage=Cpp GoLexer.g4 GoParser.g4 -o parser -visitor -no-listener
```
