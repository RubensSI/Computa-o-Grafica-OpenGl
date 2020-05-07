# **Guia de Programação OpenGL**

**Definição**

Como podemos fazer tantas coisas com o sistema gráfico OpenGL, um programa OpenGL pode ser complicado. No entanto, a estrutura básica de um programa útil pode ser simples: suas tarefas são inicializar certos estados que controlam como o OpenGL renderiza e especificar objetos a serem renderizados. 

*Renderização*  é o processo pelo qual um computador cria imagens a partir de modelos. Esses *modelos*- ou objetos, são construídos a partir de primitivas geométricas - pontos, linhas e polígonos - que são especificados por seus vértices.  

A imagem renderizada final consiste em pixels desenhados na tela; um pixel é o menor elemento visível que o hardware de exibição pode colocar na tela. Informações sobre os pixels (por exemplo, que cor eles deveriam ser) são organizadas na memória em bitplanes. Um bitplane é uma área de memória que contém um pouco de informação para cada pixel na tela; o bit pode indicar o quão vermelho um pixel em particular deve ser, por exemplo. Os bitplanes são organizados em um *framebuffer,*que contém todas as informações que o display gráfico precisa para controlar a cor e intensidade de todos os pixels na tela.



**Pipeline de renderização OpenGL**

A maioria das implementações do OpenGL tem uma ordem semelhante de operações, uma série de etapas de processamento chamadas de pipeline de renderização OpenGL. Veja o diagrama de fluxo, como mostrado na figura, não é uma regra estrita de como o OpenGL é implementado, mas fornece um guia confiável para prever o que o OpenGL fará.

O diagrama a seguir mostra a abordagem da linha de montagem de Henry Ford, que o OpenGL leva para processar dados. Os dados geométricos (vértices, linhas e polígonos) seguem o caminho através da linha de caixas que inclui avaliadores e operações por vértice, enquanto os dados de pixels (pixels, imagens e bitmaps) são tratados de forma diferente durante parte do processo. Ambos os tipos de dados passam pelas mesmas etapas finais (operações de rasterização e por fragmento) antes que os dados de pixel final sejam gravados no buffer de quadros.

