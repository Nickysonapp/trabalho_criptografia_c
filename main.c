   #include <stdio.h>
   #include <string.h>

int main() {
    char palavra[16];
    int shift;
    int tipo_sequencia;

    printf("=== SISTEMA DE CRIPTOGRAFIA DUPLA ===\n");
    
    // 1. Pedir a palavra secreta
    printf("Digite a palavra secreta (ate 15 letras, sem acentos): ");
    scanf("%15s", palavra);

    // 2. Vvalor do SHIFT
    printf("Digite o valor do SHIFT (ex: 3): ");
    scanf("%d", &shift);

    // 3. Mostrar o menu de opções
    printf("\nEscolha a sequencia matematica:\n");
    printf("1 - PA (Progressao Aritmetica)\n");
    printf("2 - PG (Progressao Geometrica)\n");
    printf("3 - Fibonacci\n");
    printf("4 - Numeros Primos\n");
    printf("Digite sua opcao: ");
    scanf("%d", &tipo_sequencia);

    int tamanho = strlen(palavra);
    int sequencia[16];
    char palavra_criptografada[16];

    // Configurar a sequência escolhida de forma simples
    if (tipo_sequencia == 1) {
        // Opção 1: PA (soma 2 a cada passo)
        int a1 = 1, r = 2;
        for (int i = 0; i < tamanho; i++) {
            sequencia[i] = a1 + (i * r);
        }
    } 
    else if (tipo_sequencia == 2) {
        // Opção 2: PG (multiplica por 2 a cada passo)
        int termo = 2;
        for (int i = 0; i < tamanho; i++) {
            sequencia[i] = termo;
            termo *= 2;
        }
    } 
    else if (tipo_sequencia == 3) {
        // Opção 3: Fibonacci
        sequencia[0] = 1;
        if (tamanho > 1) sequencia[1] = 1;
        for (int i = 2; i < tamanho; i++) {
            sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
        }
    } 
    else if (tipo_sequencia == 4) {
        // Opção 4: Números Primos fixos
        int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = 0; i < tamanho; i++) {
            sequencia[i] = primos[i];
        }
    } 
    else {
        printf("\nOpcao invalida!\n");
        return 0;
    }

    // Aplicar a criptografia (Cifra de César + Sequência)
    for (int i = 0; i < tamanho; i++) {
        int deslocamento_total = shift + sequencia[i];
        palavra_criptografada[i] = 'a' + (palavra[i] - 'a' + deslocamento_total) % 26;
    }
    palavra_criptografada[tamanho] = '\0'; // Finalizar a palavra

    // Mostrar os resultados na tela
    printf("\n--- RESULTADO DA CRIPTOGRAFIA ---\n");
    printf("Palavra original: %s\n", palavra);
    printf("Palavra codificada: %s\n", palavra_criptografada);
    printf("SHIFT: %d | Tipo: %d | Letras: %d\n", shift, tipo_sequencia, tamanho);

    // Salva tudo em um arquivo
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n", 
                palavra_criptografada, shift, tipo_sequencia, tamanho);
        fclose(arquivo);
        printf("\n[Sucesso] Dados salvos no arquivo 'resultado_criptografia.txt'!\n");
    } else {
        printf("\n[Erro] Nao foi possivel criar o arquivo.\n");
    
    }
    return 0;
    
    }
