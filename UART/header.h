typedef unsigned char u8 ;

void delay_ms(int ms );
void delay_us(int us );
void uart_init(unsigned int baud );
void uart_tx(u8 data );
void uart_tx_string(const char *message );
u8 uart_rx(void );

