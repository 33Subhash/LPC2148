typedef unsigned char u8 ;
typedef unsigned int u32 ;

void delay_ms(int ms );
void delay_us(int us );
void uart_init(unsigned int baud );
void uart_tx(u8 data );
void uart_tx_string(const char *message );
u8 uart_rx(void );
void  adc_init(void );
u32 adc_read(void );
void uart_tx_int(u32 num);
void dac_init(void );
void dac_write(u32 digital_data);
void SPI_Master_Init(void );
u8 SPI_Master_write(char data);
u8 SPI_Master_Read(void );
