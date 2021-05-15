  /// Configurações de Montagem
  #define PIN_DATA 10     // Output de Dados
  #define PIN_LATCH 12    // Output do latch
  #define PIN_CLOCK 13    // Output do Clock
  
  #define QTD_BITS 8      // Quantidade de bits controlados
  #define VAL_MAX pow( 2 , QTD_BITS ) -1    // Valor MÁXIMO representável
  
  /// Configurações de Sistema
  #define FREQ_TRANSM 9600    // Frequência de Transmissão entre a porta SERIAL
  #define NUMS_POR_LN 7       // Números por linha na saída Serial
  #define DELAY_CICLO 500
  
  void setup() {
    Serial.begin( FREQ_TRANSM );
    Serial.println("\t=== Exibidor de Números Binários ===");
    pinMode( PIN_DATA , OUTPUT );
    pinMode( PIN_LATCH , OUTPUT );
    pinMode( PIN_CLOCK , OUTPUT ); 
  }
  
  void loop() {
    static int num = 0;
    static int copy_num;        // Cópia do número num
    static int qtd_algs;        // Quantidade de algorismos do número num
    
    shiftOut( PIN_DATA , PIN_CLOCK , LSBFIRST, num );
    delay( DELAY_CICLO );
    digitalWrite( PIN_LATCH , LOW );
    digitalWrite( PIN_LATCH , HIGH );
    digitalWrite( PIN_LATCH , LOW );
    
    if( num == VAL_MAX + 1 )
      num = 0;
  
    /// Saída Serial
    
    // Espaçamento
    copy_num = num;
    qtd_algs = 0; 
    do{
      copy_num /= 10;
      qtd_algs++;  
    }while( copy_num );
  
    for( int i = 4 - qtd_algs ; i > 0 ; i-- )
      Serial.print(" ");
  
    // Número
    Serial.print(num);  
    
    // Divisão
    Serial.print(" | ");
    
  
    /// Incrementa NUM
    num++;
  
    // Quebra de Linha
    if( !( num % NUMS_POR_LN ) )
      Serial.print("\n");  
  }
