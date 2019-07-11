
int getString(char *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
int validarLetra (char letras[]);
int validarNumero (char numeros[]);
int validarFlotante(char* numeros);
int validFloat(char* numeros);

int getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int isValidInt(int numero, int maximo, int minimo);

int isValidFloat(float numero, float maximo, float minimo);
int getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

int isValidChar(char letra, char maximo, char minimo);
int getChar( char *resultado,char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);

int validNumber(char* numeros);
int validFecha(char* numeros);
int validCuit(char* cuit);
int validTipo(char* tipo);
