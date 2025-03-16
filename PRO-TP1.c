/*PROYECTO PROGRAMA PARA EL MANEJO DEL HIPERMERCADO CACHAMAY, UBICADO EN PUERTO ORDAZ, RIF-J-123456789,
TELEFONO: 0414-0463588 //// PROYECTO CREADO POR JESUS COLMENARES //// Universidad Nacional Experimental de Guayana*/

//===========================================
//LIBERIAS A USAR
//===========================================


#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <fcntl.h>
#include <io.h>
#include <uxtheme.h>
#include <commctrl.h>
#include <sys/stat.h>

#define _WIN32_WINNT 0x0603

#define CAJAS 5
#define IVA 0.16
#define TASA_BS 64.00
#define TASA_EUR 0.98
#define TASA_PES 4100.00
static WNDPROC OldEditPrecioDolarProc;


//===============================================================================
//DECLARACION E IDENTIFICACION DE TODOS LOS BOTONES USADOS EN EL PROGRAMA
//================================================================================

//BOTONES MENU PRINCIPAL
#define BTN_PRODUCTOS 100
#define BTN_CLIENTES 101
#define BTN_FACTURAS 102
#define BTN_TRABAJADORES 103
#define BTN_VENTAS 104
#define BTN_CAJAS 105
#define BTN_SALIR 106

//BOTONES INGRESO DE PRODUCTOS
#define BTN_ATRAS1 112
#define BTN_GUARDAR 113
#define BTN_LIMPIARPRODUCTO 114
#define BTN_BUSCARPRODUCTO 115
#define BTN_ELIMINAR_PRODUCTO 116
#define BTN_EDITAR_PRODUCTO 117
#define BTN_IMPRIMIR_PRODUCTOS 118


#define EDT_CODIGO_PRODUCTO 150
#define EDT_NOMBRE_PRODUCTO 151
#define EDT_CANTIDADISPONIBLE 152
#define EDT_PRECIO_DOLAR_PRODUCTO 153
#define EDT_PRECIO_BS_PRODUCTO 154
#define EDT_PRECIO_EUR_PRODUCTO 155
#define EDT_PRECIO_PES_PRODUCTO 156

//BTN LISTA DE PRODUCTOS
#define BTN_ATRAS2 160


//BOTONES MENU CLIENTES
#define BTN_INGRESARCLIENTE 500
#define BTN_LISTACLIENTE 501

//BOTONES VENTANA INGRESAR CLIENTES
#define BTN_ATRAS3 510
#define BTN_GUARDAR_CLIENTE 511
#define BTN_LIMPIAR_CLIENTE 512
#define EDT_CEDULA_CLIENTE 513
#define EDT_NOMBRE_CLIENTE 514
#define EDT_APELLIDO_CLIENTE 515
#define EDT_DIRECCION_CLIENTE 516
#define EDT_TELEFONO_CLIENTE 517

#define BTN_ELIMINAR_CLIENTE 518
#define BTN_EDITAR_CLIENTE 519
#define BTN_BUSCARCLIENTE 520
#define BTN_IMPRIMIR_CLIENTES 521

//BOTONES VENTANA LISTA CLIENTES 
#define BTN_ATRAS4 550

//BOTONES MENU EMPLEADOS
#define BTN_INGRESOEMPLEADOS 600
#define BTN_LISTAEMPLEADOS 601

//BOTONES MENU INGRESO EMPLEADOS
#define BTN_ATRAS5 602
#define BTN_GUARDAR_EMPLEADO 603
#define BTN_LIMPIAR_EMPLEADO 604
#define EDT_CEDULA_EMPLEADO 605
#define EDT_NUMERO_EMPLEADO 606
#define EDT_NOMBRE_EMPLEADO 607
#define EDT_APELLIDO_EMPLEADO 608
#define EDT_DIRECCION_EMPLEADO 609
#define EDT_CARGO_EMPLEADO 610
#define EDT_TELEFONO_EMPLEADO 611


#define BTN_EDITAR_EMPLEADO 612
#define BTN_ELIMINAR_EMPLEADO 613
#define BTN_BUSCAR_EMPLEADO 614
#define BTN_IMPRIMIR_EMPLEADOS 615

//BOTONES MENU LISTA EMPLEADOS
#define BTN_ATRAS6 616

//BOTONES MENU FACTURA
#define BTN_CREAR_FACTURA 700
#define BTN_LISTA_FACTURA 701

//BOTONES DE LA VENTANA CREAR FACTURA
#define BTN_BUSCAR_CLIENTE 702
#define BTN_AGREGAR_PRODUCTO 703
#define BTN_GUARDAR_FACTURA 704
#define BTN_IMPRIMIR_FACTURA 705
#define BTN_CERRAR_FACTURA 706
#define BTN_CERRAR 717

#define EDT_CEDULA_FACTURA 720
#define EDT_NOMBRE_FACTURA 721
#define EDT_APELLIDO_FACTURA 722
#define EDT_DIRECCION_FACTURA 723
#define EDT_TELEFONO_FACTURA 724

#define EDT_CANTIDAD_PRODUCTO_FACTURA 725
#define EDT_AGREGAR_PRODUCTO_FACTURA 726
#define EDT_CODIGO_PRODUCTO_FACTURA 727
#define EDT_ID_HIPERMERCADO 728
#define EDT_NUMERO_FACTURA 729
#define EDT_FECHA_FACTURA 730
#define EDT_CLIENTE_FACTURA 731
#define EDT_PAGO_BRUTO 732
#define EDT_PORCENTAJE_IVA 733
#define EDT_PAGO_TOTAL 734
#define EDT_CAJA_FACTURA 735
#define EDT_PAGO_BRUTOBS 736
#define EDT_PAGO_TOTALBS 737
#define IDC_CHECK_BS 738
#define IDC_CHECK_DOL 739
#define IDC_CHECK_EUR 740
#define IDC_CHECK_PES 741

//BOTONES MOSTRAR/LISTA FACTURA
#define BTN_IMPRIMIRFACTURA 801
#define BTN_GUARDARFACTURA 802
#define BTN_ELIMINAR_FACTURA 803
#define BTN_BUSCAR_FACTURA 804

//BOTONES VENTAS
#define EDT_VENTAS_DIARIAS 900
#define EDT_VENTAS_MENSUEALES 901
#define BTN_BUSCAR1 902
#define BTN_BUSCAR2 903

//BOTONES CAJAS
#define BTN_ATRAS8 1000
#define BTN_GUARDAR_CAJA 1001
#define BTN_LIMPIAR_CAJA 1002
#define EDT_NUMERO_CAJA 1010
#define EDT_BS_CAJA 1011
#define EDT_DOL_CAJA 1012
#define EDT_EUR_CAJA 1013
#define EDT_PES_CAJA 1014
#define EDT_CEDULA_ENCARGADO 1015
#define EDT_NOMBRE_ENCARGADO 1016
#define EDT_APELLIDO_ENCARGADO 1017
#define EDT_DIRECCION_ENCARGADO 1018
#define EDT_CARGO_ENCARGADO 1019
#define EDT_TELEFONO_ENCARGADO 1020
#define BTN_BUSCAR_CEDULA_ENCARGADO 1021
#define BTN_BUSCAR_CAJA 1022
#define BTN_EDITAR_CAJA 1023
#define BTN_ELIMINAR_CAJA 1024
#define BTN_IMPRIMIR_CAJA 1025

//===============================================================================================================================
//ESTRUCTURAS DE LOS DATOS DEL PROGRAMA
//===============================================================================================================================

typedef struct estrucutra_productos{
    int codigo;
    wchar_t nombre_producto[150];
    int cantidad_disponible;
    float precioBS;
    float precioDOL;
    float precioEUR;
    float precioPES;
} datos_productos;

typedef struct estructura_clientes{ 
    int cedula;
    wchar_t nombre[150];
    wchar_t apellido[150];
    wchar_t direccion[200];
    int telefono;
    int cantidad_compras;
} datos_clientes;

typedef struct estructuras_trabajador{
    int cedula_trabajador;
    int numero_empleado;
    wchar_t nombre[50];
    wchar_t apellido[50];
    wchar_t direccion[100];
    wchar_t cargo[100];
    int telefono;
} datos_trabajador;

typedef struct estructura_cajas{
    int numero_caja;
    datos_trabajador encargador; //ENCARGADO DE LA CAJA
    float bolivares_facturados;
    float dolares_facturados;
    float euros_facturados;
    float pesos_facturados;
} datos_cajas;

typedef struct estructura_facturas{
    wchar_t ID_hipermercado[15];
    int numero_factura;
    wchar_t fecha[20];
    datos_clientes cliente;
    wchar_t productos_comprados[500];
    float pago_bruto;
    float porcentajeIVA;
    float pago_total;
    wchar_t metodo_pago[50];
    datos_cajas caja;
} datos_facturas;


datos_productos d_productos[500];
int cant_productos = 0;

datos_clientes d_clientes[500];
int cant_clientes = 0;

datos_trabajador d_empleados[500];
int cant_empleados = 0;

datos_cajas d_cajas[5];
int cant_cajas = 0;

datos_facturas d_facturas[500];
int cant_facturas = 0;


//=================================================================================================================================
//FUNCIONES PRINCIPALES DEL PROGRAMA TALES COMO, VERIFICAR QUE NO HAYA DUPLICADOS, CARGAR LOS DATOS GUARDADOS EN LOS ARCHIVOS, ETC.
//=================================================================================================================================

int VerificarProducto(const wchar_t *verificador) {
    int codigo_verificar = _wtoi(verificador);

    for (int i = 0; i < cant_productos; i++) {
        if(d_productos[i].codigo == codigo_verificar){
            return 1;
        }
    }
    return 0; // Código único
}

int VerificarCliente(const wchar_t *verificador) {
    int cedula_verificar = _wtoi(verificador);

    for (int i = 0; i < cant_clientes; i++) {
        if(d_clientes[i].cedula == cedula_verificar){
            return 1;
        }
    }
    return 0; // Cédula única
}

int VerificarEmpleado(const wchar_t *verificador) {
    int cedula_verificar = _wtoi(verificador);

    for (int i = 0; i < cant_empleados; i++) {
        if(d_empleados[i].cedula_trabajador == cedula_verificar){
            return 1;
        }
    }
    return 0; // Cédula única
}

int VerificarCaja(const int numero, HWND VentCajas) {
    for (int i = 0; i < cant_cajas; i++) {
        if (d_cajas[i].numero_caja == numero) {
            
    MessageBox(VentCajas, L"La caja ya existe", L"Error", MB_ICONERROR | MB_OK);
    return 1; // El número de caja se repite

        }
    }
    return 0; // Número de caja único
}

void CargarProductos() {
    // Configurar la localización para el manejo de cadenas y números
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");

    // Abrir el archivo "productos.dat" en modo lectura con codificación UTF-8
    FILE *archivo = _wfopen(L"productos.dat", L"r, ccs=UTF-8");
    if (!archivo) {
        fwprintf(stderr, L"Error al abrir el archivo productos.dat.\n");
        return;
    }

    // Leer cada registro de producto hasta alcanzar el final del archivo o el máximo permitido
    while (cant_productos < 500) {
        int dummy;
        // Se lee el ID (aunque no se utiliza) y se comprueba que se haya leído correctamente
        if (fwscanf(archivo, L"ID: %d\n", &dummy) != 1)
            break;
        if (fwscanf(archivo, L"Codigo: %d\n", &d_productos[cant_productos].codigo) != 1)
            break;
        
        // Leer el nombre del producto (hasta 149 caracteres)
        wchar_t bufferNombre[150];
        if (fwscanf(archivo, L"Nombre Producto: %149[^\n]\n", bufferNombre) != 1)
            break;
        wcscpy_s(d_productos[cant_productos].nombre_producto, 150, bufferNombre);
        
        if (fwscanf(archivo, L"Cantidad Disponible: %d\n", &d_productos[cant_productos].cantidad_disponible) != 1)
            break;
        if (fwscanf(archivo, L"Precio Dolar: %f\n", &d_productos[cant_productos].precioDOL) != 1)
            break;
        if (fwscanf(archivo, L"Precio Bolivares: %f\n", &d_productos[cant_productos].precioBS) != 1)
            break;
        if (fwscanf(archivo, L"Precio Euros: %f\n", &d_productos[cant_productos].precioEUR) != 1)
            break;
        if (fwscanf(archivo, L"Precio Pesos: %f\n", &d_productos[cant_productos].precioPES) != 1)
            break;
        
        // Leer la línea separadora (por ejemplo: "---------------------")
        wchar_t separador[30];
        fwscanf(archivo, L"%29[^\n]\n", separador);
        
        cant_productos++;
    }
    
    fclose(archivo);
}

void CargarClientes(){
    // Configurar la localización para el manejo de cadenas y números
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");

    // Abrir el archivo "clientes.dat" en modo lectura con codificación UTF-8
    FILE *archivo = _wfopen(L"clientes.dat", L"r, ccs=UTF-8");
    if (!archivo) {
        fwprintf(stderr, L"Error al abrir el archivo clientes.dat.\n");
        return;
    }
    
    // Leer cada registro de cliente hasta llegar al final o al máximo permitido
    while(cant_clientes < 500) {
        // Leer la cédula
        if(fwscanf(archivo, L"Cedula: %d\n", &d_clientes[cant_clientes].cedula) != 1)
            break;
        
        // Leer el nombre (hasta 149 caracteres)
        wchar_t bufferNombre[150];
        if(fwscanf(archivo, L"Nombre: %149[^\n]\n", bufferNombre) != 1)
            break;
        wcscpy_s(d_clientes[cant_clientes].nombre, 150, bufferNombre);
        
        // Leer el apellido (hasta 149 caracteres)
        wchar_t bufferApellido[150];
        if(fwscanf(archivo, L"Apellido: %149[^\n]\n", bufferApellido) != 1)
            break;
        wcscpy_s(d_clientes[cant_clientes].apellido, 150, bufferApellido);
        
        // Leer la dirección (hasta 199 caracteres)
        wchar_t bufferDireccion[200];
        if(fwscanf(archivo, L"Direccion: %199[^\n]\n", bufferDireccion) != 1)
            break;
        wcscpy_s(d_clientes[cant_clientes].direccion, 200, bufferDireccion);
        
        // Leer el teléfono
        if(fwscanf(archivo, L"Telefono: %d\n", &d_clientes[cant_clientes].telefono) != 1)
            break;
        
        // Leer la línea separadora (por ejemplo: "---------------------")
        wchar_t separador[30];
        fwscanf(archivo, L"%29[^\n]\n", separador);
        
        cant_clientes++;
    }
    
    fclose(archivo);
}

void CargarEmpleado(){
    FILE *archivo = fopen("empleados.dat", "r");
    if (!archivo) {
        // No existe el archivo o hubo error al abrir
        return;
    }
    // Se leerán los registros hasta el final del archivo "feof = file end of file"
    while(1) {
        if(fscanf(archivo, "Cedula: %d\n", &d_empleados[cant_empleados].cedula_trabajador) != 1)
            break;
        
        if(fscanf(archivo, "Numero Empleado: %d\n", &d_empleados[cant_empleados].numero_empleado) != 1)
            break;
        
        // Leer el nombre (hasta 49 caracteres, se omite el prefijo "Nombre: ")
        wchar_t nombre[50];
        if(fwscanf(archivo, L"Nombre: %49[^\n]\n", nombre) != 1)
            break;
        wcscpy_s(d_empleados[cant_empleados].nombre, 50, nombre);
        
        // Leer el apellido (hasta 49 caracteres, se omite el prefijo "Apellido: ")
        wchar_t apellido[50];
        if(fwscanf(archivo, L"Apellido: %49[^\n]\n", apellido) != 1)
            break;
        wcscpy_s(d_empleados[cant_empleados].apellido, 50, apellido);
        
        // Leer la dirección (hasta 99 caracteres, se omite el prefijo "Direccion: ")
        wchar_t direccion[100];
        if(fwscanf(archivo, L"Direccion: %99[^\n]\n", direccion) != 1)
            break;
        wcscpy_s(d_empleados[cant_empleados].direccion, 100, direccion);
        
        // Leer el cargo (hasta 99 caracteres, se omite el prefijo "Cargo: ")
        wchar_t cargo[100];
        if(fwscanf(archivo, L"Cargo: %99[^\n]\n", cargo) != 1)
            break;
        wcscpy_s(d_empleados[cant_empleados].cargo, 100, cargo);
        
        if(fscanf(archivo, "Telefono: %d\n", &d_empleados[cant_empleados].telefono) != 1)
            break;
        
        // Leer la línea separadora (por ejemplo: "---------------------")
        wchar_t separador[30];
        fwscanf(archivo, L"%29[^\n]\n", separador);
        
        cant_empleados++;
    }
    fclose(archivo);
}

void CargarCajas(){ 
    // Configurar la localización para manejo de cadenas y números
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");

    // Abrir el archivo en modo lectura, utilizando codificación UTF-8
    FILE *archivo = _wfopen(L"cajas.dat", L"r, ccs=UTF-8");
    if (!archivo) {
        fwprintf(stderr, L"Error al abrir el archivo cajas.dat.\n");
        return;
    }

    while (cant_cajas < 5) {
        // Comprobar si se pudo leer el primer campo; de lo contrario, salir del bucle
        if (fwscanf(archivo, L"Numero Caja: %d\n", &d_cajas[cant_cajas].numero_caja) != 1)
            break;
        
        if (fwscanf(archivo, L"Monto Facturado en Bs.: %f\n", &d_cajas[cant_cajas].bolivares_facturados) != 1)
            break;
        
        if (fwscanf(archivo, L"Monto Facturado en $: %f\n", &d_cajas[cant_cajas].dolares_facturados) != 1)
            break;
        
        if (fwscanf(archivo, L"Monto Facturado en EUR: %f\n", &d_cajas[cant_cajas].euros_facturados) != 1)
            break;
        
        if (fwscanf(archivo, L"Monto Facturado en PES: %f\n", &d_cajas[cant_cajas].pesos_facturados) != 1)
            break;
        
        if (fwscanf(archivo, L"Cedula Encargado: %d\n", &d_cajas[cant_cajas].encargador.cedula_trabajador) != 1)
            break;
        
        // Leer Nombre Encargado
        wchar_t bufferNombre[50];
        if (fwscanf(archivo, L"Nombre Encargado: %49[^\n]\n", bufferNombre) != 1)
            break;
        wcscpy_s(d_cajas[cant_cajas].encargador.nombre, 50, bufferNombre);
        
        // Leer Apellido Encargado
        wchar_t bufferApellido[50];
        if (fwscanf(archivo, L"Apellido Encargado: %49[^\n]\n", bufferApellido) != 1)
            break;
        wcscpy_s(d_cajas[cant_cajas].encargador.apellido, 50, bufferApellido);
        
        // Leer Direccion Encargado
        wchar_t bufferDireccion[100];
        if (fwscanf(archivo, L"Direccion Encargado: %99[^\n]\n", bufferDireccion) != 1)
            break;
        wcscpy_s(d_cajas[cant_cajas].encargador.direccion, 100, bufferDireccion);
        
        if (fwscanf(archivo, L"Telefono Encargado: %d\n", &d_cajas[cant_cajas].encargador.telefono) != 1)
            break;
        
        // Leer la línea separadora (por ejemplo: "---------------------")
        wchar_t separador[30];
        fwscanf(archivo, L"%29[^\n]\n", separador);
        
        cant_cajas++;
    }
    
    fclose(archivo);
}

void CargarFacturas() {
    // Configurar la localización para manejo de caracteres y que los números usen punto como separador decimal
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");

    // Abrir el archivo con codificación UTF-8
    FILE *archivo = _wfopen(L"facturas.dat", L"r, ccs=UTF-8");
    if (!archivo) {
        wprintf(L"Error al abrir el archivo facturas.dat.\n");
        return;
    }
    
    while (cant_facturas < 500) {
        datos_facturas factura = {0};

        // Leer ID Hipermercado
        if (fwscanf(archivo, L"ID Hipermercado: %14ls\n", factura.ID_hipermercado) != 1)
            break;
        // Leer Número de Factura
        if (fwscanf(archivo, L"Número Factura: %d\n", &factura.numero_factura) != 1)
            break;
        // Leer Fecha
        if (fwscanf(archivo, L"Fecha: %19ls\n", factura.fecha) != 1)
            break;
        // Leer datos del cliente: cedula, nombre, dirección y teléfono
        if (fwscanf(archivo, L"Cliente: %d %149[^,], %199[^,], Tel: %d\n",
                    &factura.cliente.cedula,
                    factura.cliente.nombre,
                    factura.cliente.direccion,
                    &factura.cliente.telefono) != 4)
            break;
        // Leer la línea de "Productos Comprados:" (sin extraer contenido)
        if (fwscanf(archivo, L"Productos Comprados:\n") < 0)
            break;
        // Leer el contenido de Productos Comprados (por ejemplo, "G" o "A")
        if (fwscanf(archivo, L"%499[^\n]\n", factura.productos_comprados) != 1)
            break;
        // Leer Pago Bruto, ignorando el contenido entre paréntesis (la moneda)
        if (fwscanf(archivo, L"Pago Bruto (%*[^)]): %f\n", &factura.pago_bruto) != 1)
            break;
        // Leer Porcentaje IVA
        if (fwscanf(archivo, L"Porcentaje IVA: %f\n", &factura.porcentajeIVA) != 1)
            break;
        // Leer Pago Total, ignorando el contenido entre paréntesis
        if (fwscanf(archivo, L"Pago Total (%*[^)]): %f\n", &factura.pago_total) != 1)
            break;
        // Leer Número de Caja
        if (fwscanf(archivo, L"Caja: %d\n", &factura.caja.numero_caja) != 1)
            break;
        // Leer Método de pago
        wchar_t bufferMetodo[10];
        if (fwscanf(archivo, L"Método de pago: %9ls\n", bufferMetodo) != 1)
            break;
        wcscpy_s(factura.metodo_pago, 10, bufferMetodo);
        // Leer la línea separadora (por ejemplo: "---------------------")
        wchar_t separador[30];
        if (fwscanf(archivo, L"%29[^\n]\n", separador) != 1)
            break;
        
        d_facturas[cant_facturas++] = factura;
    }
    
    fclose(archivo);
}

void ProductosEnListView(HWND ListViewProducto) {
// Agregar columnas al ListView
LVCOLUMN col = {0};
col.mask = LVCF_TEXT | LVCF_WIDTH;

// Primera columna: "ID"
col.pszText = L"Codigo";
col.cx = 100; // ancho en píxeles
ListView_InsertColumn(ListViewProducto, 0, &col);

// Segunda columna: "Nombre"
col.pszText = L"Nombre";
col.cx = 200;
ListView_InsertColumn(ListViewProducto, 1, &col);

// Tercera columna: "Cantidad"
col.pszText = L"Cantidad Disponible";
col.cx = 200;
ListView_InsertColumn(ListViewProducto, 2, &col);

//Cuarta Columna: "Precio en Bolivares"
col.pszText= L"Precio Bs(Unitario)";
col.cx=130;
ListView_InsertColumn(ListViewProducto, 3, &col);

//Quinta Columna: "Precio en Dolares"
col.pszText = L"Precio $";
col.cx = 100;
ListView_InsertColumn(ListViewProducto, 4,&col);

//Sexta Columna: "Precio en euros"
col.pszText = L"Precio Eur";
col.cx = 100;
ListView_InsertColumn(ListViewProducto, 5, &col);

col.pszText = L"Precio Pesos";
col.cx = 100;
ListView_InsertColumn(ListViewProducto, 6, &col);


//Proceso para mostrar los productos ya almacenados

    LVITEM lvItem = {0};
    lvItem.mask = LVIF_TEXT;
    wchar_t buffer[128];
    for (int i = 0; i < cant_productos; i++) {
        LVITEM lvItem = {0};
        lvItem.mask = LVIF_TEXT;
        lvItem.iItem = i;
        
        // Insertar la primera columna (por ejemplo, mostrar el código)
        swprintf_s(buffer, 128, L"%d", d_productos[i].codigo);
        lvItem.pszText = buffer;
        int index = ListView_InsertItem(ListViewProducto, &lvItem);

        // Segunda columna: Nombre del producto
        ListView_SetItemText(ListViewProducto, index, 1, d_productos[i].nombre_producto);

        // Tercera columna: Cantidad disponible
        swprintf_s(buffer, 128, L"%d", d_productos[i].cantidad_disponible);
        ListView_SetItemText(ListViewProducto, index, 2, buffer);

        // Cuarta columna: Precio en Bolivares
        
        swprintf_s(buffer, 128, L"%.2f", d_productos[i].precioBS);
        ListView_SetItemText(ListViewProducto, index,3, buffer)

        swprintf_s(buffer, 128, L"%.2f", d_productos[i].precioDOL);
        ListView_SetItemText(ListViewProducto, index, 4, buffer);

        swprintf_s(buffer, 128, L"%.2f", d_productos[i].precioEUR);
        ListView_SetItemText(ListViewProducto, index, 5, buffer);

        swprintf_s(buffer, 128, L"%.2f", d_productos[i].precioPES);
        ListView_SetItemText(ListViewProducto, index, 6, buffer);
    }
}

void ClientesEnListView(HWND ListViewCliente){
    // Agregar columnas al ListView
    LVCOLUMN col = {0};
    col.mask = LVCF_TEXT | LVCF_WIDTH;

    // Primera columna: "Cédula"
    col.pszText = L"Cédula";
    col.cx = 100; // ancho en píxeles
    ListView_InsertColumn(ListViewCliente, 0, &col);

    // Segunda columna: "Nombre"
    col.pszText = L"Nombre";
    col.cx = 200;
    ListView_InsertColumn(ListViewCliente, 1, &col);

    // Tercera columna: "Apellido"
    col.pszText = L"Apellido";
    col.cx = 200;
    ListView_InsertColumn(ListViewCliente, 2, &col);

    // Cuarta columna: "Dirección"
    col.pszText = L"Dirección";
    col.cx = 300;
    ListView_InsertColumn(ListViewCliente, 3, &col);

    // Quinta columna: "Teléfono"
    col.pszText = L"Teléfono";
    col.cx = 150;
    ListView_InsertColumn(ListViewCliente, 4, &col);

    // Proceso para mostrar los clientes ya almacenados
    wchar_t buffer[128];
    for (int i = 0; i < cant_clientes; i++) {
        LVITEM lvItem = {0};
        lvItem.mask = LVIF_TEXT;
        lvItem.iItem = i;

        // Insertar la primera columna (por ejemplo, mostrar la cédula)
        swprintf_s(buffer, 128, L"%d", d_clientes[i].cedula);
        lvItem.pszText = buffer;
        int index = ListView_InsertItem(ListViewCliente, &lvItem);

        // Segunda columna: Nombre del cliente
        ListView_SetItemText(ListViewCliente, index, 1, d_clientes[i].nombre);

        // Tercera columna: Apellido del cliente
        ListView_SetItemText(ListViewCliente, index, 2, d_clientes[i].apellido);

        // Cuarta columna: Dirección del cliente
        ListView_SetItemText(ListViewCliente, index, 3, d_clientes[i].direccion);

        // Quinta columna: Teléfono del cliente
        swprintf_s(buffer, 128, L"%d", d_clientes[i].telefono);
        ListView_SetItemText(ListViewCliente, index, 4, buffer);
    }
}

void EmpleadosEnListView(HWND ListViewEmpleado){
    // Agregar columnas al ListView
    LVCOLUMN col = {0};
    col.mask = LVCF_TEXT | LVCF_WIDTH;

    // Primera columna: "Cédula"
    col.pszText = L"Cédula";
    col.cx = 100; // ancho en píxeles
    ListView_InsertColumn(ListViewEmpleado, 0, &col);

    // Segunda columna: "Número de Empleado"
    col.pszText = L"Número Empleado";
    col.cx = 150;
    ListView_InsertColumn(ListViewEmpleado, 1, &col);

    // Tercera columna: "Nombre"
    col.pszText = L"Nombre";
    col.cx = 150;
    ListView_InsertColumn(ListViewEmpleado, 2, &col);

    // Cuarta columna: "Apellido"
    col.pszText = L"Apellido";
    col.cx = 150;
    ListView_InsertColumn(ListViewEmpleado, 3, &col);

    // Quinta columna: "Dirección"
    col.pszText = L"Dirección";
    col.cx = 200;
    ListView_InsertColumn(ListViewEmpleado, 4, &col);

    // Sexta columna: "Cargo"
    col.pszText = L"Cargo";
    col.cx = 150;
    ListView_InsertColumn(ListViewEmpleado, 5, &col);

    // Séptima columna: "Teléfono"
    col.pszText = L"Teléfono";
    col.cx = 100;
    ListView_InsertColumn(ListViewEmpleado, 6, &col);

    // Proceso para mostrar los empleados ya almacenados
    wchar_t buffer[128];
    for (int i = 0; i < cant_empleados; i++) {
        LVITEM lvItem = {0};
        lvItem.mask = LVIF_TEXT;
        lvItem.iItem = i;

        // Insertar la primera columna (por ejemplo, mostrar la cédula)
        swprintf_s(buffer, 128, L"%d", d_empleados[i].cedula_trabajador);
        lvItem.pszText = buffer;
        int index = ListView_InsertItem(ListViewEmpleado, &lvItem);

        // Segunda columna: Número de Empleado
        swprintf_s(buffer, 128, L"%d", d_empleados[i].numero_empleado);
        ListView_SetItemText(ListViewEmpleado, index, 1, buffer);

        // Tercera columna: Nombre del empleado
        ListView_SetItemText(ListViewEmpleado, index, 2, d_empleados[i].nombre);

        // Cuarta columna: Apellido del empleado
        ListView_SetItemText(ListViewEmpleado, index, 3, d_empleados[i].apellido);

        // Quinta columna: Dirección del empleado
        ListView_SetItemText(ListViewEmpleado, index, 4, d_empleados[i].direccion);

        // Sexta columna: Cargo del empleado
        ListView_SetItemText(ListViewEmpleado, index, 5, d_empleados[i].cargo);

        // Séptima columna: Teléfono del empleado
        swprintf_s(buffer, 128, L"%d", d_empleados[i].telefono);
        ListView_SetItemText(ListViewEmpleado, index, 6, buffer);
    }
}

void FacturasEnListView(HWND ListViewFactura) {
    // Agregar columnas al ListView
    LVCOLUMN col = {0};
    col.mask = LVCF_TEXT | LVCF_WIDTH;

    // Primera columna: "ID Hipermercado"
    col.pszText = L"ID Hipermercado";
    col.cx = 150; // ancho en píxeles
    ListView_InsertColumn(ListViewFactura, 0, &col);

    // Segunda columna: "Número de Factura"
    col.pszText = L"Número de Factura";
    col.cx = 150;
    ListView_InsertColumn(ListViewFactura, 1, &col);

    // Tercera columna: "Fecha"
    col.pszText = L"Fecha";
    col.cx = 150;
    ListView_InsertColumn(ListViewFactura, 2, &col);

    // Cuarta columna: "Cliente"
    col.pszText = L"Cliente";
    col.cx = 200;
    ListView_InsertColumn(ListViewFactura, 3, &col);

    // Quinta columna: "Pago Bruto"
    col.pszText = L"Pago Bruto";
    col.cx = 100;
    ListView_InsertColumn(ListViewFactura, 4, &col);

    // Sexta columna: "Porcentaje IVA"
    col.pszText = L"Porcentaje IVA";
    col.cx = 100;
    ListView_InsertColumn(ListViewFactura, 5, &col);

    // Séptima columna: "Pago Total"
    col.pszText = L"Pago Total";
    col.cx = 100;
    ListView_InsertColumn(ListViewFactura, 6, &col);

    // Octava columna: "Caja"
    col.pszText = L"Caja";
    col.cx = 50;
    ListView_InsertColumn(ListViewFactura, 7, &col);

    // Proceso para mostrar las facturas ya almacenadas
    wchar_t buffer[128];
    for (int i = 0; i < cant_facturas; i++) {
        LVITEM lvItem = {0};
        lvItem.mask = LVIF_TEXT;
        lvItem.iItem = i;

        // Insertar la primera columna (por ejemplo, mostrar el ID Hipermercado)
        lvItem.pszText = d_facturas[i].ID_hipermercado;
        int index = ListView_InsertItem(ListViewFactura, &lvItem);

        // Segunda columna: Número de Factura
        swprintf_s(buffer, 128, L"%d", d_facturas[i].numero_factura);
        ListView_SetItemText(ListViewFactura, index, 1, buffer);

        // Tercera columna: Fecha
        ListView_SetItemText(ListViewFactura, index, 2, d_facturas[i].fecha);

        // Cuarta columna: Cliente
        ListView_SetItemText(ListViewFactura, index, 3, d_facturas[i].cliente.nombre);

        // Quinta columna: Pago Bruto
        swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_bruto);
        ListView_SetItemText(ListViewFactura, index, 4, buffer);

        // Sexta columna: Porcentaje IVA
        swprintf_s(buffer, 128, L"%.2f", d_facturas[i].porcentajeIVA);
        ListView_SetItemText(ListViewFactura, index, 5, buffer);

        // Séptima columna: Pago Total
        swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_total);
        ListView_SetItemText(ListViewFactura, index, 6, buffer);

        // Octava columna: Caja
        swprintf_s(buffer, 128, L"%d", d_facturas[i].caja.numero_caja);
        ListView_SetItemText(ListViewFactura, index, 7, buffer);
    }
}

void CajasEnListView(HWND ListViewCaja){
    // Agregar columnas al ListView
    LVCOLUMN col = {0};
    col.mask = LVCF_TEXT | LVCF_WIDTH;

    // Primera columna: "Número de Caja"
    col.pszText = L"Número de Caja";
    col.cx = 100; // ancho en píxeles
    ListView_InsertColumn(ListViewCaja, 0, &col);

    // Segunda columna: "Encargado"
    col.pszText = L"Encargado";
    col.cx = 200;
    ListView_InsertColumn(ListViewCaja, 1, &col);

    // Tercera columna: "Bolívares Facturados"
    col.pszText = L"Bolívares Facturados";
    col.cx = 150;
    ListView_InsertColumn(ListViewCaja, 2, &col);

    // Cuarta columna: "Dólares Facturados"
    col.pszText = L"Dólares Facturados";
    col.cx = 150;
    ListView_InsertColumn(ListViewCaja, 3, &col);

    // Quinta columna: "Euros Facturados"
    col.pszText = L"Euros Facturados";
    col.cx = 150;
    ListView_InsertColumn(ListViewCaja, 4, &col);

    // Proceso para mostrar las cajas ya almacenadas
    wchar_t buffer[128];
    for (int i = 0; i < cant_cajas; i++) {
        LVITEM lvItem = {0};
        lvItem.mask = LVIF_TEXT;
        lvItem.iItem = i;

        // Insertar la primera columna (por ejemplo, mostrar el número de caja)
        swprintf_s(buffer, 128, L"%d", d_cajas[i].numero_caja);
        lvItem.pszText = buffer;
        int index = ListView_InsertItem(ListViewCaja, &lvItem);

        // Segunda columna: Encargado de la caja
        ListView_SetItemText(ListViewCaja, index, 1, d_cajas[i].encargador.nombre);

        // Tercera columna: Bolívares facturados
        swprintf_s(buffer, 128, L"%.2f", d_cajas[i].bolivares_facturados);
        ListView_SetItemText(ListViewCaja, index, 2, buffer);

        // Cuarta columna: Dólares facturados
        swprintf_s(buffer, 128, L"%.2f", d_cajas[i].dolares_facturados);
        ListView_SetItemText(ListViewCaja, index, 3, buffer);

        // Quinta columna: Euros facturados
        swprintf_s(buffer, 128, L"%.2f", d_cajas[i].euros_facturados);
        ListView_SetItemText(ListViewCaja, index, 4, buffer);
    }

}

//===================================================================================================================
//FUNCIONES CALLBACKS PARA EL MANEJO Y EDICION DE LAS VENTANAS
//===================================================================================================================

LRESULT CALLBACK VentanaPrincipal(HWND vent, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HINSTANCE instancia;


    switch (msg) {
        case WM_CREATE: {
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;
           
            CreateWindowEx(0, L"BUTTON", L"PRODUCTOS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 100, 120, 150, 40, vent, (HMENU)BTN_PRODUCTOS, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"EMPLEADOS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 100, 240, 150, 40, vent, (HMENU)BTN_TRABAJADORES, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"VENTAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 100, 360, 150, 40, vent, (HMENU)BTN_VENTAS, instancia, NULL);


            CreateWindowEx(0, L"BUTTON", L"CLIENTES", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 530, 120, 150, 40, vent, (HMENU)BTN_CLIENTES, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"FACTURAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 530, 240, 150, 40, vent, (HMENU)BTN_FACTURAS, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"CAJAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 530, 360, 150, 40, vent, (HMENU)BTN_CAJAS, instancia, NULL);

            CreateWindowEx(0, L"BUTTON", L"SALIR",   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 650, 510, 100, 25, vent, (HMENU)BTN_SALIR, instancia, NULL);
            break;
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(vent, &ps);
            RECT rect;
            GetClientRect(vent, &rect);
        
            // Crear una fuente grande para el título
            HFONT hFontLarge = CreateFont(
                48, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial")
            );
        
            // Seleccionar la fuente grande en el contexto de dispositivo
            HGDIOBJ hOldFont = SelectObject(hdc, hFontLarge);
        
            // Dibujar el título grande en la parte superior de la ventana, centrado horizontalmente
            DrawText(hdc, L"HIPERMERCADO CACHAMAY", -1, &rect, DT_CENTER | DT_TOP | DT_SINGLELINE);
        
            // Restaurar la fuente original
            SelectObject(hdc, hOldFont);
        
            // Eliminar la fuente grande creada
            DeleteObject(hFontLarge);
        
            // Ajustar el rectángulo para dibujar el texto más pequeño debajo del título
            rect.top += 60; // Ajusta este valor según sea necesario para dejar espacio entre los textos
        
            // Crear una fuente más pequeña para el RIF y número de teléfono
            HFONT hFontSmall = CreateFont(
                24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial")
            );
        
            // Seleccionar la fuente más pequeña en el contexto de dispositivo
            hOldFont = SelectObject(hdc, hFontSmall);
        
            
            DrawText(hdc, L"RIF: J-12345678-9 - Teléfono: 0414-0463588", -1, &rect, DT_CENTER | DT_TOP | DT_SINGLELINE);
        
            
            SelectObject(hdc, hOldFont);
        
            
            DeleteObject(hFontSmall);
        
            EndPaint(vent, &ps);
            break;
        }

        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case BTN_PRODUCTOS: {
                    HWND VentProductos = CreateWindowEx(0, L"CL_LISTAPRODUCTOS", L"PRODUCTOS", WS_OVERLAPPEDWINDOW, 5, 10, 1080, 720, NULL, NULL, instancia, NULL);
                    ShowWindow(VentProductos, SW_SHOW);
                    UpdateWindow(VentProductos);
                    break;
                }

                case BTN_CLIENTES:{
                HWND VentCliente = CreateWindowEx(0, L"CL_VentanaCliente", L"Clientes", WS_OVERLAPPEDWINDOW, 10,10,1080,720,NULL, NULL, instancia, NULL);
                ShowWindow(VentCliente, SW_SHOW);
                UpdateWindow(VentCliente);
                    break;
                }

                case BTN_TRABAJADORES :{
                    HWND VentanaEmpleados = CreateWindowEx(0, L"CL_VentanaEmpleados", L"Empleados", WS_OVERLAPPEDWINDOW, 5,5,1080,720,NULL, NULL, instancia, NULL);
                    ShowWindow(VentanaEmpleados, SW_SHOW);
                    UpdateWindow(VentanaEmpleados);
                    break;
                }

                case BTN_FACTURAS:{

                    HWND VentFactura = CreateWindowEx(0, L"CL_VentanaFacturas", L"Facturas", WS_OVERLAPPEDWINDOW, 200,200,400,400,NULL, NULL, instancia, NULL);
                    ShowWindow(VentFactura, SW_SHOW);
                    UpdateWindow(VentFactura);

                    break;
                }

                case BTN_CAJAS:{ 

                HWND VentCajas = CreateWindowEx(0, L"CL_VentanaCajas", L"Cajas", WS_OVERLAPPEDWINDOW, 15,15,950,700,NULL, NULL, instancia, NULL);
                ShowWindow(VentCajas, SW_SHOW);
                UpdateWindow(VentCajas);
                break;

                }
                
                case BTN_VENTAS: {
                    HWND VentVentas = CreateWindowEx(0, L"CL_VentanaVentas", L"Ventas", WS_OVERLAPPEDWINDOW, 15,15,950,700,NULL, NULL, instancia, NULL);
                ShowWindow(VentVentas,SW_SHOW);
                UpdateWindow(VentVentas);
                    break;
                }

                case BTN_SALIR: {
                    if (MessageBox(vent, L"Estas Seguro que quieres salir?", L"Salir", MB_OKCANCEL | MB_ICONQUESTION) == IDOK) {
                        SendMessage(vent, WM_CLOSE, 0, 0);
                    }
                    break;
                }
            }
            break;
        }
       
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
       
        default: {
            return DefWindowProc(vent, msg, wParam, lParam);
        }
    }
    return 0;
}

LRESULT CALLBACK EditPrecioDolarProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CHAR: {
            // Permitir dígitos (0-9), punto ('.') y retroceso
            if ((wParam >= L'0' && wParam <= L'9') || wParam == L'.' || wParam == L'\b') {
                break; // se permite
            }
            return 0; // se bloquea la entrada no válida
        }
        default:
            break;
    }
    return CallWindowProc(OldEditPrecioDolarProc, hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK VentanaProductos(HWND VentProductos, UINT msg, WPARAM wParam, LPARAM lParam){

   static HINSTANCE instancia;
   
  HWND ListViewProducto;
   

 switch(msg){

    case WM_CREATE:{
        instancia = ((LPCREATESTRUCT)lParam)->hInstance;

        {
        CreateWindowEx(0, L"BUTTON", L"ATRAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 30, 625, 150, 25, VentProductos, (HMENU)BTN_ATRAS2, instancia, NULL);
        CreateWindowEx(0, L"BUTTON", L"IMPRIMIR PRODUCTOS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 230, 625, 180, 25, VentProductos, (HMENU)BTN_IMPRIMIR_PRODUCTOS, instancia, NULL);

        
        CreateWindowEx(0, L"BUTTON", L"GUARDAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 330, 205, 150, 40, VentProductos, (HMENU)BTN_GUARDAR, instancia, NULL);
        CreateWindowEx(0, L"BUTTON", L"LIMPIAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 330, 255 , 150, 40, VentProductos, (HMENU)BTN_LIMPIARPRODUCTO, instancia, NULL);
        CreateWindowEx(0, L"BUTTON", L"BUSCAR PRODUCTO", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 490, 205 , 150, 40, VentProductos, (HMENU)BTN_BUSCARPRODUCTO, instancia, NULL);

        // Control estático y de edición para el código del producto
        CreateWindowEx(0, L"STATIC", L"CODIGO", SS_CENTER | WS_CHILD | WS_VISIBLE, 10, 70, 100, 25, VentProductos, NULL, instancia, NULL);
        CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER | WS_TABSTOP, 130, 70, 150, 25, VentProductos, (HMENU)EDT_CODIGO_PRODUCTO, instancia, NULL);

        // Control estático y de edición para el nombre del producto
        CreateWindowEx(0, L"STATIC", L"NOMBRE", SS_CENTER | WS_CHILD | WS_VISIBLE, 10, 120, 100, 25, VentProductos, NULL, instancia, NULL);
        CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_TABSTOP, 130, 120, 150, 25, VentProductos, (HMENU)EDT_NOMBRE_PRODUCTO, instancia, NULL);

        // Control estático y de edición para la cantidad disponible del producto
        CreateWindowEx(0, L"STATIC", L"CANTIDAD DISPONIBLE", SS_CENTER | WS_CHILD | WS_VISIBLE, 10, 170, 180, 25, VentProductos, NULL, instancia, NULL);
        CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 205, 170, 80, 25, VentProductos, (HMENU)EDT_CANTIDADISPONIBLE, instancia, NULL);

        // Control estático y de edición para el precio en dólares del producto
        CreateWindowEx(0, L"STATIC", L"PRECIO $", SS_CENTER | WS_CHILD | WS_VISIBLE, 10, 220, 100, 25, VentProductos, NULL, instancia, NULL);
        HWND hEditPrecio = CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 130, 220, 150, 25, VentProductos, (HMENU)EDT_PRECIO_DOLAR_PRODUCTO, instancia, NULL);

        // Subclassing para permitir solo dígitos, punto y retroceso
        OldEditPrecioDolarProc = (WNDPROC)SetWindowLongPtr(hEditPrecio, GWLP_WNDPROC, (LONG_PTR)EditPrecioDolarProc);

        // Control estático y de edición para el precio en Bolívares del producto
        CreateWindowEx(0, L"STATIC", L"PRECIO BS", SS_CENTER | WS_CHILD | WS_VISIBLE, 310, 70, 100, 25, VentProductos, NULL, instancia, NULL);
        CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_READONLY, 430, 70, 150, 25, VentProductos, (HMENU)EDT_PRECIO_BS_PRODUCTO, instancia, NULL);

        // Control estático y de edición para el precio en Euros del producto
        CreateWindowEx(0, L"STATIC", L"PRECIO EUR", SS_CENTER | WS_CHILD | WS_VISIBLE, 310, 120, 100, 25, VentProductos, NULL, instancia, NULL);
        CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_READONLY, 430, 120, 150, 25, VentProductos, (HMENU)EDT_PRECIO_EUR_PRODUCTO, instancia, NULL);

        // Control estático y de edición para el precio en Pesos del producto
        CreateWindowEx(0, L"STATIC", L"PRECIO PES", SS_CENTER | WS_CHILD | WS_VISIBLE, 310, 170, 100, 25, VentProductos, NULL, instancia, NULL);
        CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_READONLY, 430, 170, 150, 25, VentProductos, (HMENU)EDT_PRECIO_PES_PRODUCTO, instancia, NULL);


        CreateWindowEx(0, L"STATIC",
            L"Consejos de Ingreso:\n\n"
            L"- Código: Solo números enteros.\n\n"
            L"- Nombre: Ingrese la marca, modelo, peso, etc.\n\n"
            L"- Cantidad: Sólo números enteros.\n\n"
            L"- Precio $: Use números y el punto (.) para decimales.",
            SS_LEFT | WS_CHILD | WS_VISIBLE | SS_CENTER, 710, 65, 200, 210, VentProductos, NULL, instancia, NULL);

        ListViewProducto = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Productos", WS_CHILD|WS_VISIBLE|LVS_REPORT|LVS_SINGLESEL|LVS_SORTASCENDING, 33,300, 1000,300, VentProductos, NULL, instancia, NULL);
        ListView_SetExtendedListViewStyle(ListViewProducto,LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS |LVS_EX_FULLROWSELECT|LVS_EX_HEADERINALLVIEWS);
        ProductosEnListView(ListViewProducto);
        
        }
       

        break;
    }

    case WM_COMMAND:{
        if(LOWORD(wParam) == EDT_PRECIO_DOLAR_PRODUCTO && HIWORD(wParam) == EN_CHANGE) {
            wchar_t buffer[100];
            GetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO), buffer, 100);
            float precioDOL = (float)_wtof(buffer);
        
            // Calcular los valores en las otras monedas
            float precioBS  = precioDOL * TASA_BS;
            float precioEUR = precioDOL * TASA_EUR;
            float precioPES = precioDOL * TASA_PES;
        
            wchar_t bufferBS[100], bufferEUR[100], bufferPES[100];
            swprintf_s(bufferBS, 100, L"%.2f", precioBS);
            swprintf_s(bufferEUR, 100, L"%.2f", precioEUR);
            swprintf_s(bufferPES, 100, L"%.2f", precioPES);
        
            SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_BS_PRODUCTO), bufferBS);
            SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_EUR_PRODUCTO), bufferEUR);
            SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_PES_PRODUCTO), bufferPES);
        }
       
        switch(LOWORD(wParam)){

                case BTN_GUARDAR:{

                    if(GetWindowTextLength(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO)) == 0 || GetWindowTextLength(GetDlgItem(VentProductos, EDT_NOMBRE_PRODUCTO)) == 0 || GetWindowTextLength(GetDlgItem(VentProductos, EDT_CANTIDADISPONIBLE)) == 0 || GetWindowTextLength(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO)) == 0){
                        MessageBox(VentProductos, L"Debe llenar todos los campos", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    wchar_t buffer[150];

                        HWND hCodigoProducto = GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO);
                        GetWindowTextW(hCodigoProducto, buffer, 100);
                        d_productos[cant_productos].codigo = _wtoi(buffer);
                        if(VerificarProducto(buffer)){
                            MessageBox(VentProductos,  L"El producto ya existe, verifique nuevamente",L"Error", MB_ICONERROR | MB_OK);
                            break;
                        }
                       
                        GetDlgItemText(VentProductos, EDT_NOMBRE_PRODUCTO, buffer, 100);
                        wcscpy_s(d_productos[cant_productos].nombre_producto,150, buffer);
                        

                        GetDlgItemText(VentProductos, EDT_CANTIDADISPONIBLE, buffer, 100);
                        d_productos[cant_productos].cantidad_disponible = _wtoi(buffer);

                        GetDlgItemText(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO, buffer, 100);
                        d_productos[cant_productos].precioDOL = (float)_wtof(buffer);


                        d_productos[cant_productos].precioBS = d_productos[cant_productos].precioDOL * TASA_BS;
                        d_productos[cant_productos].precioEUR = d_productos[cant_productos].precioDOL * TASA_EUR;
                        d_productos[cant_productos].precioPES = d_productos[cant_productos].precioDOL * TASA_PES;


                        FILE *archivo_productos;
                        archivo_productos = fopen("productos.dat", "a+");
                        if(archivo_productos == NULL){
                        MessageBox(VentProductos, L"ERROR", L"ERROR AL CREAR EL ARCHIVO", MB_OKCANCEL);
                        return 1;
                             }
                        
                           
                           fprintf(archivo_productos, "ID: %i\n", cant_productos);
                           fprintf(archivo_productos, "Codigo: %d\n",d_productos[cant_productos].codigo);
                           fprintf(archivo_productos, "Nombre Producto: %ls\n", d_productos[cant_productos].nombre_producto);
                           fprintf(archivo_productos, "Cantidad Disponible: %d\n", d_productos[cant_productos].cantidad_disponible);
                           fprintf(archivo_productos, "Precio Dolar: %.2f\n", d_productos[cant_productos].precioDOL);
                           fprintf(archivo_productos, "Precio Bolivares: %.2f\n", d_productos[cant_productos].precioBS);
                           fprintf(archivo_productos, "Precio Euros: %.2f\n", d_productos[cant_productos].precioEUR);
                           fprintf(archivo_productos, "Precio Pesos: %.2f\n", d_productos[cant_productos].precioPES);
                           fprintf(archivo_productos, "---------------------\n");
                           cant_productos++;
                           fclose(archivo_productos);

                          MessageBox(VentProductos, L"Producto Guardado Exitosamente", L"Guardado", MB_OK);
                          
                          SetWindowText(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO), L"");
                          SetWindowText(GetDlgItem(VentProductos, EDT_NOMBRE_PRODUCTO), L"");
                          SetWindowText(GetDlgItem(VentProductos, EDT_CANTIDADISPONIBLE), L"");
                          SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO), L"");
                          SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_BS_PRODUCTO), L"");
                          SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_EUR_PRODUCTO), L"");
                          SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_PES_PRODUCTO), L"");
                          
                          DestroyWindow(VentProductos);
                          HWND nVentProductos = CreateWindowEx(0, L"CL_LISTAPRODUCTOS", L"PRODUCTOS", WS_OVERLAPPEDWINDOW, 5, 10, 1080, 720, NULL, NULL, instancia, NULL);
                          ShowWindow(nVentProductos, SW_SHOW);
                          UpdateWindow(nVentProductos);

                        
                        break;
                }

                case BTN_ATRAS2:{   
                DestroyWindow(VentProductos);
                
            }

                case BTN_BUSCARPRODUCTO:{

                    if(GetWindowTextLength(GetDlgItem(VentProductos,EDT_CODIGO_PRODUCTO)) == 0){
                        MessageBox(VentProductos, L"Debes ingresar el codigo del producto para buscarlo", L"Error", MB_ICONERROR|MB_OK);
                        break;
                    }

                    // Buscar el producto por código
                    wchar_t buffer[100];
                    GetWindowText(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO), buffer, 100);
                    int codigo = _wtoi(buffer);

                    int productoEncontrado = 0;
                    for (int i = 0; i < cant_productos; i++) {
                        if (codigo == d_productos[i].codigo) {
                            SetWindowText(GetDlgItem(VentProductos, EDT_NOMBRE_PRODUCTO), d_productos[i].nombre_producto);
                            swprintf_s(buffer, 100, L"%d", d_productos[i].cantidad_disponible);
                            SetWindowText(GetDlgItem(VentProductos, EDT_CANTIDADISPONIBLE), buffer);
                            swprintf_s(buffer, 100, L"%.2f", d_productos[i].precioDOL);
                            SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO), buffer);
                            swprintf_s(buffer, 100, L"%.2f", d_productos[i].precioBS);
                            SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_BS_PRODUCTO), buffer);
                            swprintf_s(buffer, 100, L"%.2f", d_productos[i].precioEUR);
                            SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_EUR_PRODUCTO), buffer);
                            swprintf_s(buffer, 100, L"%.2f", d_productos[i].precioPES);
                            SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_PES_PRODUCTO), buffer);
                            productoEncontrado = 1;
                            break;
                        }
                    }

                    if (!productoEncontrado) {
                        MessageBox(VentProductos, L"Producto no encontrado", L"Error", MB_ICONERROR | MB_OK);
                    }

                    // Crear botón de eliminar producto
                    CreateWindowEx(0, L"BUTTON", L"ELIMINAR PRODUCTO", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 490, 255, 150, 40, VentProductos, (HMENU)BTN_ELIMINAR_PRODUCTO, instancia, NULL);

                    // Eliminar el botón de guardar si existe
                    HWND hGuardarButton = GetDlgItem(VentProductos, BTN_GUARDAR);
                    if (hGuardarButton) {
                        DestroyWindow(hGuardarButton);
                    }

                    // Crear botón de editar producto
                    CreateWindowEx(0, L"BUTTON", L"EDITAR PRODUCTO", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 330, 205, 150, 40, VentProductos, (HMENU)BTN_EDITAR_PRODUCTO, instancia, NULL);

                    break;
                }
            
                case BTN_EDITAR_PRODUCTO:{
                    if (GetWindowTextLength(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentProductos, EDT_NOMBRE_PRODUCTO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentProductos, EDT_CANTIDADISPONIBLE)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO)) == 0) {
                    MessageBox(VentProductos, L"Debe llenar todos los campos", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }
            
                wchar_t buffer[150];
                int codigo_producto;
            
                // Obtener el código del producto
                GetWindowText(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO), buffer, 100);
                codigo_producto = _wtoi(buffer);
            
                // Buscar el producto en la estructura
                int productoEncontrado = -1;
                for (int i = 0; i < cant_productos; i++) {
                    if (d_productos[i].codigo == codigo_producto) {
                        productoEncontrado = i;
                        break;
                    }
                }
            
                if (productoEncontrado == -1) {
                    MessageBox(VentProductos, L"Producto no encontrado", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }
            
                // Actualizar los datos del producto en la estructura
                GetDlgItemText(VentProductos, EDT_NOMBRE_PRODUCTO, buffer, 150);
                wcscpy_s(d_productos[productoEncontrado].nombre_producto, 150, buffer);
            
                GetDlgItemText(VentProductos, EDT_CANTIDADISPONIBLE, buffer, 100);
                d_productos[productoEncontrado].cantidad_disponible = _wtoi(buffer);
            
                GetDlgItemText(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO, buffer, 100);
                d_productos[productoEncontrado].precioDOL = (float)_wtof(buffer);
            
                d_productos[productoEncontrado].precioBS = d_productos[productoEncontrado].precioDOL * TASA_BS;
                d_productos[productoEncontrado].precioEUR = d_productos[productoEncontrado].precioDOL * TASA_EUR;
                d_productos[productoEncontrado].precioPES = d_productos[productoEncontrado].precioDOL * TASA_PES;
            
                // Actualizar el archivo de productos
                FILE *archivo_productos = fopen("productos.dat", "w");
                if (archivo_productos == NULL) {
                    MessageBox(VentProductos, L"Error al abrir el archivo de productos", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }
            
                for (int i = 0; i < cant_productos; i++) {
                    fprintf(archivo_productos, "ID: %i\n", i);
                    fprintf(archivo_productos, "Codigo: %d\n", d_productos[i].codigo);
                    fprintf(archivo_productos, "Nombre Producto: %ls\n", d_productos[i].nombre_producto);
                    fprintf(archivo_productos, "Cantidad Disponible: %d\n", d_productos[i].cantidad_disponible);
                    fprintf(archivo_productos, "Precio Dolar: %.2f\n", d_productos[i].precioDOL);
                    fprintf(archivo_productos, "Precio Bolivares: %.2f\n", d_productos[i].precioBS);
                    fprintf(archivo_productos, "Precio Euros: %.2f\n", d_productos[i].precioEUR);
                    fprintf(archivo_productos, "Precio Pesos: %.2f\n", d_productos[i].precioPES);
                    fprintf(archivo_productos, "---------------------\n");
                }
            
                fclose(archivo_productos);
            
                MessageBox(VentProductos, L"Producto editado exitosamente", L"Éxito", MB_OK);
            
                // Limpiar los campos de entrada
                SetWindowText(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO), L"");
                SetWindowText(GetDlgItem(VentProductos, EDT_NOMBRE_PRODUCTO), L"");
                SetWindowText(GetDlgItem(VentProductos, EDT_CANTIDADISPONIBLE), L"");
                SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO), L"");
                SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_BS_PRODUCTO), L"");
                SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_EUR_PRODUCTO), L"");
                SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_PES_PRODUCTO), L"");
            
                // Actualizar la vista de la lista de productos
                DestroyWindow(VentProductos);
                HWND nVentProductos = CreateWindowEx(0, L"CL_LISTAPRODUCTOS", L"PRODUCTOS", WS_OVERLAPPEDWINDOW, 5, 10, 1080, 720, NULL, NULL, instancia, NULL);
                ShowWindow(nVentProductos, SW_SHOW);
                UpdateWindow(nVentProductos);
            
                break;
                }

                case BTN_ELIMINAR_PRODUCTO:{
                    if (GetWindowTextLength(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO)) == 0) {
                        MessageBox(VentProductos, L"Debe ingresar el código del producto para eliminar", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }
                
                    wchar_t buffer[100];
                    GetWindowText(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO), buffer, 100);
                    int codigo_producto = _wtoi(buffer);
                
                    // Buscar el producto en la estructura
                    int productoEncontrado = -1;
                    for (int i = 0; i < cant_productos; i++) {
                        if (d_productos[i].codigo == codigo_producto) {
                            productoEncontrado = i;
                            break;
                        }
                    }
                
                    if (productoEncontrado == -1) {
                        MessageBox(VentProductos, L"Producto no encontrado", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }
                
                    // Eliminar el producto de la estructura
                    for (int i = productoEncontrado; i < cant_productos - 1; i++) {
                        d_productos[i] = d_productos[i + 1];
                    }
                    cant_productos--;
                
                    // Actualizar el archivo de productos
                    FILE *archivo_productos = fopen("productos.dat", "w");
                    if (archivo_productos == NULL) {
                        MessageBox(VentProductos, L"Error al abrir el archivo de productos", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }
                
                    for (int i = 0; i < cant_productos; i++) {
                        fprintf(archivo_productos, "ID: %i\n", i);
                        fprintf(archivo_productos, "Codigo: %d\n", d_productos[i].codigo);
                        fprintf(archivo_productos, "Nombre Producto: %ls\n", d_productos[i].nombre_producto);
                        fprintf(archivo_productos, "Cantidad Disponible: %d\n", d_productos[i].cantidad_disponible);
                        fprintf(archivo_productos, "Precio Dolar: %.2f\n", d_productos[i].precioDOL);
                        fprintf(archivo_productos, "Precio Bolivares: %.2f\n", d_productos[i].precioBS);
                        fprintf(archivo_productos, "Precio Euros: %.2f\n", d_productos[i].precioEUR);
                        fprintf(archivo_productos, "Precio Pesos: %.2f\n", d_productos[i].precioPES);
                        fprintf(archivo_productos, "---------------------\n");
                    }
                
                    fclose(archivo_productos);
                
                    MessageBox(VentProductos, L"Producto eliminado exitosamente", L"Éxito", MB_OK);
                
                    // Limpiar los campos de entrada
                    SetWindowText(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_NOMBRE_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_CANTIDADISPONIBLE), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_BS_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_EUR_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_PES_PRODUCTO), L"");
                
                    // Actualizar la vista de la lista de productos
                    DestroyWindow(VentProductos);
                    HWND nVentProductos = CreateWindowEx(0, L"CL_LISTAPRODUCTOS", L"PRODUCTOS", WS_OVERLAPPEDWINDOW, 5, 10, 1080, 720, NULL, NULL, instancia, NULL);
                    ShowWindow(nVentProductos, SW_SHOW);
                    UpdateWindow(nVentProductos);
                
                    break;
                }

                case BTN_IMPRIMIR_PRODUCTOS: {
                        FILE *archivo_cvs = fopen("ReporteProductos.csv", "w");
                        if (archivo_cvs == NULL) {
                            MessageBox(VentProductos, L"Error al crear el archivo cvs", L"Error", MB_ICONERROR | MB_OK);
                            break;
                        }

                        // Escribir encabezados
                        fwprintf(archivo_cvs, L"Codigo; Nombre Producto; Cantidad Disponible; Precio Dolar; Precio Bolivares; Precio Euros; Precio Pesos\n");

                        // Escribir datos de productos
                        for (int i = 0; i < cant_productos; i++) {
                            fwprintf(archivo_cvs, L"%d;%ls;%d;%.2f;%.2f;%.2f;%.2f\n",
                                     d_productos[i].codigo,
                                     d_productos[i].nombre_producto,
                                     d_productos[i].cantidad_disponible,
                                     d_productos[i].precioDOL,
                                     d_productos[i].precioBS,
                                     d_productos[i].precioEUR,
                                     d_productos[i].precioPES);
                        }

                        fclose(archivo_cvs);
                        MessageBox(VentProductos, L"Productos exportados a ReporteProductos.csv exitosamente", L"Éxito", MB_OK);
                        break;
                    }

                case BTN_LIMPIARPRODUCTO: {
                    SetWindowText(GetDlgItem(VentProductos, EDT_CODIGO_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_NOMBRE_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_CANTIDADISPONIBLE), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_DOLAR_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_BS_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_EUR_PRODUCTO), L"");
                    SetWindowText(GetDlgItem(VentProductos, EDT_PRECIO_PES_PRODUCTO), L"");
                    break;
                }

        } 

        break;

    }

    case WM_CLOSE:{ 
        DestroyWindow(VentProductos);
        break;
        }
    
    case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(VentProductos, &ps);
            RECT rect;
            GetClientRect(VentProductos, &rect);
        
            // Crear una fuente grande para el título
            HFONT hFontLarge = CreateFont(
                48, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial")
            );
        
            // Seleccionar la fuente grande en el contexto de dispositivo
            HGDIOBJ hOldFont = SelectObject(hdc, hFontLarge);
        
            // Dibujar el título grande en la parte superior de la ventana, centrado horizontalmente
            DrawText(hdc, L"PRODUCTOS", -1, &rect, DT_CENTER | DT_TOP | DT_SINGLELINE);
        
            // Restaurar la fuente original
            SelectObject(hdc, hOldFont);
        
            // Eliminar la fuente grande creada
            DeleteObject(hFontLarge);
        
            // Ajustar el rectángulo para dibujar el texto más pequeño debajo del título
            rect.top += 60; // Ajusta este valor según sea necesario para dejar espacio entre los textos

            break;
        }

    

        default:
            {
                return DefWindowProc(VentProductos, msg, wParam, lParam);
            }
            
 }

 return 0;
}

LRESULT CALLBACK VentanaClientes(HWND VentClientes, UINT msg, WPARAM wParam, LPARAM lParam){
 
    static HINSTANCE instancia;
    HWND ListViewCliente;

    switch(msg){
     
    case WM_PAINT:{

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(VentClientes, &ps);
        RECT rect;
        GetClientRect(VentClientes, &rect);

        // Crear una fuente grande para el título
        HFONT hFontLarge = CreateFont(
            48, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial")
        );

        // Seleccionar la fuente grande en el contexto de dispositivo
        HGDIOBJ hOldFont = SelectObject(hdc, hFontLarge);

        // Dibujar el título grande en la parte superior de la ventana, centrado horizontalmente
        DrawText(hdc, L"CLIENTES", -1, &rect, DT_CENTER | DT_TOP | DT_SINGLELINE);

        // Restaurar la fuente original
        SelectObject(hdc, hOldFont);

        // Eliminar la fuente grande creada
        DeleteObject(hFontLarge);

        break;
    }
                
     case WM_CREATE:{
               instancia = ((LPCREATESTRUCT)lParam)->hInstance;
        
  // Crear un GroupBox para agrupar los controles
  HWND groupBox = CreateWindowEx(0, L"BUTTON", L"Datos del Cliente", WS_VISIBLE | WS_CHILD | BS_GROUPBOX, 10, 70, 350, 260, VentClientes, NULL, instancia, NULL);

  // Botón "ATRAS"
  CreateWindowEx(0, L"BUTTON", L"ATRAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 445, 650, 150, 25, VentClientes, (HMENU)BTN_ATRAS4, instancia, NULL);
  CreateWindowEx(0, L"BUTTON", L"IMPRIMIR CLIENTES", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 380, 294, 150, 25, VentClientes, (HMENU)BTN_IMPRIMIR_CLIENTES, instancia, NULL);


  // Control estático y de edición para la cédula del cliente
  CreateWindowEx(0, L"STATIC", L"CÉDULA", SS_CENTER | WS_CHILD | WS_VISIBLE, 30, 100, 100, 25, VentClientes, NULL, instancia, NULL);
  CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 140, 100, 200, 25, VentClientes, (HMENU)EDT_CEDULA_CLIENTE, instancia, NULL);

  // Control estático y de edición para el nombre del cliente
  CreateWindowEx(0, L"STATIC", L"NOMBRE", SS_CENTER | WS_CHILD | WS_VISIBLE, 30, 140, 100, 25, VentClientes, NULL, instancia, NULL);
  CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 140, 140, 200, 25, VentClientes, (HMENU)EDT_NOMBRE_CLIENTE, instancia, NULL);

// Control estático y de edición para el apellido del cliente
CreateWindowEx(0, L"STATIC", L"APELLIDO", SS_CENTER | WS_CHILD | WS_VISIBLE, 30, 180, 100, 25, VentClientes, NULL, instancia, NULL);
CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 140, 180, 200, 25, VentClientes, (HMENU)EDT_APELLIDO_CLIENTE, instancia, NULL);

// Control estático y de edición para la dirección del cliente
CreateWindowEx(0, L"STATIC", L"DIRECCIÓN", SS_CENTER | WS_CHILD | WS_VISIBLE, 30, 220, 100, 25, VentClientes, NULL, instancia, NULL);
CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 140, 220, 200, 25, VentClientes, (HMENU)EDT_DIRECCION_CLIENTE, instancia, NULL);

// Control estático y de edición para el teléfono del cliente
CreateWindowEx(0, L"STATIC", L"TELÉFONO", SS_CENTER | WS_CHILD | WS_VISIBLE, 30, 260, 100, 25, VentClientes, NULL, instancia, NULL);
CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 140, 260, 200, 25, VentClientes, (HMENU)EDT_TELEFONO_CLIENTE, instancia, NULL);

CreateWindowEx(0, L"BUTTON", L"GUARDAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 380, 78, 150, 25, VentClientes, (HMENU)BTN_GUARDAR_CLIENTE, instancia, NULL);
CreateWindowEx(0, L"BUTTON", L"LIMPIAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 380, 150, 150, 25, VentClientes, (HMENU)BTN_LIMPIAR_CLIENTE, instancia, NULL);

CreateWindowEx(0, L"BUTTON", L"BUSCAR CLIENTE", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 380, 222, 150, 25, VentClientes, (HMENU)BTN_BUSCARCLIENTE, instancia, NULL);



CreateWindowEx(0, L"STATIC", 
    L"Consejos de Ingreso:\n\n"
    L"- Cédula: Solo números enteros.\n\n"
    L"- Nombre: Ingrese el nombre completo.\n\n"
    L"- Apellido: Ingrese el apellido completo.\n\n"
    L"- Dirección: Ingrese la dirección completa.\n\n"
    L"- Teléfono: Solo números enteros.",
    SS_LEFT | WS_CHILD | WS_VISIBLE | SS_CENTER, 700, 80, 200, 210, VentClientes, NULL, instancia, NULL);


//Vista tipo lista de los clientes
ListViewCliente = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Clientes", WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING, 45, 340, 955, 300, VentClientes, NULL, instancia, NULL);
ListView_SetExtendedListViewStyle(ListViewCliente, LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);
ClientesEnListView(ListViewCliente);
     
     break;
    
    }

     case WM_COMMAND:{

           switch(LOWORD(wParam)){

            case BTN_ATRAS4: {
                DestroyWindow(VentClientes);
               break;
            }
            
            case BTN_GUARDAR_CLIENTE:{

                if(GetWindowTextLength(GetDlgItem(VentClientes, EDT_NOMBRE_CLIENTE)) == 0 || GetWindowTextLength(GetDlgItem(VentClientes, EDT_APELLIDO_CLIENTE)) == 0 || GetWindowTextLength(GetDlgItem(VentClientes, EDT_DIRECCION_CLIENTE)) == 0 || GetWindowTextLength(GetDlgItem(VentClientes, EDT_TELEFONO_CLIENTE)) == 0){
                    MessageBox(VentClientes, L"Debe llenar todos los campos", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }
            
                wchar_t buffer[200];

                GetDlgItemText(VentClientes, EDT_CEDULA_CLIENTE, buffer, 200);
                d_clientes[cant_clientes].cedula = _wtoi(buffer);

                GetDlgItemText(VentClientes, EDT_NOMBRE_CLIENTE, buffer, 200);
                wcscpy_s(d_clientes[cant_clientes].nombre, 150, buffer);

                GetDlgItemText(VentClientes, EDT_APELLIDO_CLIENTE, buffer, 200);
                wcscpy_s(d_clientes[cant_clientes].apellido, 150, buffer);

                GetDlgItemText(VentClientes, EDT_DIRECCION_CLIENTE, buffer, 200);
                wcscpy_s(d_clientes[cant_clientes].direccion, 200, buffer);

                d_clientes[cant_clientes].telefono = GetDlgItemInt(VentClientes, EDT_TELEFONO_CLIENTE, NULL, FALSE);

                FILE *archivo_clientes;
                archivo_clientes = fopen("clientes.dat", "a");
                if (archivo_clientes == NULL) {
                    MessageBox(VentClientes, L"ERROR", L"ERROR AL CREAR EL ARCHIVO", MB_OKCANCEL);
                    return 1;
                }

                fprintf(archivo_clientes, "Cedula: %d\n", d_clientes[cant_clientes].cedula);
                fprintf(archivo_clientes, "Nombre: %ls\n", d_clientes[cant_clientes].nombre);
                fprintf(archivo_clientes, "Apellido: %ls\n", d_clientes[cant_clientes].apellido);
                fprintf(archivo_clientes, "Direccion: %ls\n", d_clientes[cant_clientes].direccion);
                fprintf(archivo_clientes, "Telefono: %d\n", d_clientes[cant_clientes].telefono);
                fprintf(archivo_clientes, "---------------------\n");

                fclose(archivo_clientes);

                cant_clientes++;
                MessageBox(VentClientes, L"Cliente guardado exitosamente", L"Éxito", MB_OK);
                SetWindowText(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_NOMBRE_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_APELLIDO_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_DIRECCION_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_TELEFONO_CLIENTE), L"");

                
                DestroyWindow(VentClientes);
                HWND nVentClientes = CreateWindowEx(0, L"CL_VentanaCliente", L"Clientes", WS_OVERLAPPEDWINDOW, 10,10,1080,720,NULL, NULL, instancia, NULL);
                ShowWindow(nVentClientes, SW_SHOW);
                UpdateWindow(nVentClientes);
                

                break;
            }
            
            case BTN_LIMPIAR_CLIENTE:{

                SetWindowText(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_NOMBRE_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_APELLIDO_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_DIRECCION_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_TELEFONO_CLIENTE), L"");

                HWND nVentClientes = CreateWindowEx(0, L"CL_VentanaCliente", L"Clientes", WS_OVERLAPPEDWINDOW, 10,10,1080,720,NULL, NULL, instancia, NULL);
                DestroyWindow(VentClientes);
                ShowWindow(nVentClientes, SW_SHOW);
                UpdateWindow(nVentClientes);

                break;
            }

            case BTN_BUSCARCLIENTE:{
                if(GetWindowTextLength(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE)) == 0){
                    MessageBox(VentClientes, L"Debe introducir la cedula del cliente para continuar", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }

                // Buscar el cliente por cédula
                wchar_t buffer[100];
                GetWindowText(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE), buffer, 100);
                int cedula = _wtoi(buffer);

                int clienteEncontrado = 0;
                for (int i = 0; i < cant_clientes; i++) {
                    if (cedula == d_clientes[i].cedula) {
                        SetWindowText(GetDlgItem(VentClientes, EDT_NOMBRE_CLIENTE), d_clientes[i].nombre);
                        SetWindowText(GetDlgItem(VentClientes, EDT_APELLIDO_CLIENTE), d_clientes[i].apellido);
                        SetWindowText(GetDlgItem(VentClientes, EDT_DIRECCION_CLIENTE), d_clientes[i].direccion);
                        swprintf_s(buffer, 100, L"%d", d_clientes[i].telefono);
                        SetWindowText(GetDlgItem(VentClientes, EDT_TELEFONO_CLIENTE), buffer);
                        clienteEncontrado = 1;
                        break;
                    }
                }

                if (!clienteEncontrado) {
                    MessageBox(VentClientes, L"Cliente no encontrado", L"Error", MB_ICONERROR | MB_OK);
                }

            
                // Eliminar el botón de guardar si existe
                HWND hGuardarButton = GetDlgItem(VentClientes, BTN_GUARDAR_CLIENTE);
                if (hGuardarButton) {
                    DestroyWindow(hGuardarButton);
                }

                HWND hLimpiarButton = GetDlgItem(VentClientes, BTN_LIMPIAR_CLIENTE);
                if (hLimpiarButton) {
                    DestroyWindow(hLimpiarButton);
                }

                // Crear botón de editar cliente
                CreateWindowEx(0, L"BUTTON", L"EDITAR CLIENTE", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 380, 78, 150, 25, VentClientes, (HMENU)BTN_EDITAR_CLIENTE, instancia, NULL);

                // Crear botón de eliminar cliente
                CreateWindowEx(0, L"BUTTON", L"ELIMINAR CLIENTE", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 380, 150, 150, 25, VentClientes, (HMENU)BTN_ELIMINAR_CLIENTE, instancia, NULL);
                
                CreateWindowEx(0, L"BUTTON", L"LIMPIAR DATOS", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | BS_CENTER, 125, 295, 120, 25, VentClientes, (HMENU)BTN_LIMPIAR_CLIENTE, instancia, NULL);

                break;
            }

            case BTN_EDITAR_CLIENTE:{
                // Verificar que no estén vacíos los campos necesarios
                if(GetWindowTextLength(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE)) == 0 ||
                   GetWindowTextLength(GetDlgItem(VentClientes, EDT_NOMBRE_CLIENTE)) == 0 ||
                   GetWindowTextLength(GetDlgItem(VentClientes, EDT_APELLIDO_CLIENTE)) == 0 ||
                   GetWindowTextLength(GetDlgItem(VentClientes, EDT_DIRECCION_CLIENTE)) == 0 ||
                   GetWindowTextLength(GetDlgItem(VentClientes, EDT_TELEFONO_CLIENTE)) == 0)
                {
                    MessageBox(VentClientes, L"Debe llenar todos los campos", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }

                wchar_t buffer[200];
                // Obtener la cédula y buscar el cliente correspondiente
                GetDlgItemText(VentClientes, EDT_CEDULA_CLIENTE, buffer, 200);
                int cedula_cliente = _wtoi(buffer);
                int indiceCliente = -1;
                for (int i = 0; i < cant_clientes; i++){
                    if(d_clientes[i].cedula == cedula_cliente){
                        indiceCliente = i;
                        break;
                    }
                }
                if(indiceCliente == -1){
                    MessageBox(VentClientes, L"Cliente no encontrado", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }

                // Actualizar la información del cliente en la estructura global
                GetDlgItemText(VentClientes, EDT_NOMBRE_CLIENTE, buffer, 200);
                wcscpy_s(d_clientes[indiceCliente].nombre, 150, buffer);

                GetDlgItemText(VentClientes, EDT_APELLIDO_CLIENTE, buffer, 200);
                wcscpy_s(d_clientes[indiceCliente].apellido, 150, buffer);

                GetDlgItemText(VentClientes, EDT_DIRECCION_CLIENTE, buffer, 200);
                wcscpy_s(d_clientes[indiceCliente].direccion, 200, buffer);

                d_clientes[indiceCliente].telefono = GetDlgItemInt(VentClientes, EDT_TELEFONO_CLIENTE, NULL, FALSE);

                // Reescribir el archivo con todos los clientes actualizados
                FILE *archivo_clientes = fopen("clientes.dat", "w");
                if(archivo_clientes == NULL){
                    MessageBox(VentClientes, L"Error al abrir el archivo de clientes", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }
                for (int i = 0; i < cant_clientes; i++){
                    fprintf(archivo_clientes, "Cedula: %d\n", d_clientes[i].cedula);
                    fprintf(archivo_clientes, "Nombre: %ls\n", d_clientes[i].nombre);
                    fprintf(archivo_clientes, "Apellido: %ls\n", d_clientes[i].apellido);
                    fprintf(archivo_clientes, "Direccion: %ls\n", d_clientes[i].direccion);
                    fprintf(archivo_clientes, "Telefono: %d\n", d_clientes[i].telefono);
                    fprintf(archivo_clientes, "---------------------\n");
                }
                fclose(archivo_clientes);

                MessageBox(VentClientes, L"Cliente editado exitosamente", L"Éxito", MB_OK);

                // Limpiar los campos
                SetWindowText(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_NOMBRE_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_APELLIDO_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_DIRECCION_CLIENTE), L"");
                SetWindowText(GetDlgItem(VentClientes, EDT_TELEFONO_CLIENTE), L"");

                //Actualizar ventana
                DestroyWindow(VentClientes);
            HWND nVentClientes = CreateWindowEx(0, L"CL_VentanaCliente", L"Clientes", WS_OVERLAPPEDWINDOW, 10, 10, 1080, 720, NULL, NULL, instancia, NULL);
            ShowWindow(nVentClientes, SW_SHOW);
            UpdateWindow(nVentClientes);
                break;
            }

            case BTN_ELIMINAR_CLIENTE:{

            if (GetWindowTextLength(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE)) == 0) {
                MessageBox(VentClientes, L"Debe ingresar la cédula del cliente para eliminar", L"Error", MB_ICONERROR | MB_OK);
                break;
            }

            wchar_t buffer[100];
            GetWindowText(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE), buffer, 100);
            int cedula_cliente = _wtoi(buffer);

            // Buscar el cliente en la estructura
            int clienteEncontrado = -1;
            for (int i = 0; i < cant_clientes; i++) {
                if (d_clientes[i].cedula == cedula_cliente) {
                    clienteEncontrado = i;
                    break;
                }
            }

            if (clienteEncontrado == -1) {
                MessageBox(VentClientes, L"Cliente no encontrado", L"Error", MB_ICONERROR | MB_OK);
                break;
            }

            // Eliminar el cliente de la estructura
            for (int i = clienteEncontrado; i < cant_clientes - 1; i++) {
                d_clientes[i] = d_clientes[i + 1];
            }
            cant_clientes--;

            // Actualizar el archivo de clientes
            FILE *archivo_clientes = fopen("clientes.dat", "w");
            if (archivo_clientes == NULL) {
                MessageBox(VentClientes, L"Error al abrir el archivo de clientes", L"Error", MB_ICONERROR | MB_OK);
                break;
            }

            for (int i = 0; i < cant_clientes; i++) {
                fprintf(archivo_clientes, "Cedula: %d\n", d_clientes[i].cedula);
                fprintf(archivo_clientes, "Nombre: %ls\n", d_clientes[i].nombre);
                fprintf(archivo_clientes, "Apellido: %ls\n", d_clientes[i].apellido);
                fprintf(archivo_clientes, "Direccion: %ls\n", d_clientes[i].direccion);
                fprintf(archivo_clientes, "Telefono: %d\n", d_clientes[i].telefono);
                fprintf(archivo_clientes, "---------------------\n");
            }

            fclose(archivo_clientes);

            MessageBox(VentClientes, L"Cliente eliminado exitosamente", L"Éxito", MB_OK);

            // Limpiar los campos de entrada
            SetWindowText(GetDlgItem(VentClientes, EDT_CEDULA_CLIENTE), L"");
            SetWindowText(GetDlgItem(VentClientes, EDT_NOMBRE_CLIENTE), L"");
            SetWindowText(GetDlgItem(VentClientes, EDT_APELLIDO_CLIENTE), L"");
            SetWindowText(GetDlgItem(VentClientes, EDT_DIRECCION_CLIENTE), L"");
            SetWindowText(GetDlgItem(VentClientes, EDT_TELEFONO_CLIENTE), L"");

            // Actualizar la vista de la lista de clientes
            DestroyWindow(VentClientes);
            HWND nVentClientes = CreateWindowEx(0, L"CL_VentanaCliente", L"Clientes", WS_OVERLAPPEDWINDOW, 10, 10, 1080, 720, NULL, NULL, instancia, NULL);
            ShowWindow(nVentClientes, SW_SHOW);
            UpdateWindow(nVentClientes);


            }
       
            case BTN_IMPRIMIR_CLIENTES:{

                FILE *archivo_cvs = fopen("ReporteClientes.csv", "w");
                if (archivo_cvs == NULL) {
                    MessageBox(VentClientes, L"Error al crear el archivo cvs", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }

                // Escribir encabezados
                fwprintf(archivo_cvs, L"Cedula; Nombre; Apellido; Direccion; Telefono\n");

                // Escribir datos de clientes
                for (int i = 0; i < cant_clientes; i++) {
                    fwprintf(archivo_cvs, L"%d;%ls;%ls;%ls;%d\n",
                             d_clientes[i].cedula,
                             d_clientes[i].nombre,
                             d_clientes[i].apellido,
                             d_clientes[i].direccion,
                             d_clientes[i].telefono);
                }

                fclose(archivo_cvs);
                MessageBox(VentClientes, L"Clientes exportados a ReporteClientes.csv exitosamente", L"Éxito", MB_OK);

                break;
            }
        }

        break;
     }

     case WM_CLOSE:{
            DestroyWindow(VentClientes);
            break;
        }

        default:{

           return DefWindowProc(VentClientes, msg, wParam, lParam);
         
        } 

    }

    return 0;
}

LRESULT CALLBACK VentanaEmpleados(HWND VentEmpleados, UINT msg, WPARAM wParam, LPARAM lParam){
 static HINSTANCE instancia;
 HWND ListViewEmpleado;

 //Variables y datos para el ComboBox de los cargos
 int nItems;
 const wchar_t* cargos[] = {L"Encargado Caja", L"Encargado Almacen", L"Reponedor", L"Carnicero", L"Personal de limpieza", L"Cajero", L"Recursos Humanos", L"Seguridad"};
 nItems = (sizeof(cargos) / sizeof(cargos[0]));

    switch(msg){
     
        case WM_CLOSE:{
            DestroyWindow(VentEmpleados);
            break;
        }

        case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(VentEmpleados, &ps);
            RECT rect;
            GetClientRect(VentEmpleados, &rect);

            // Crear una fuente grande para el título
            HFONT hFontLarge = CreateFont(
                48, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial")
            );

            // Seleccionar la fuente grande en el contexto de dispositivo
            HGDIOBJ hOldFont = SelectObject(hdc, hFontLarge);

            // Dibujar el título grande en la parte superior de la ventana, centrado horizontalmente
            DrawText(hdc, L"EMPLEADOS", -1, &rect, DT_CENTER | DT_TOP | DT_SINGLELINE);

            // Restaurar la fuente original
            SelectObject(hdc, hOldFont);

            // Eliminar la fuente grande creada
            DeleteObject(hFontLarge);

            break;
        }

        case WM_CREATE:{
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;
   
            // Botón "ATRAS"
            CreateWindowEx(0, L"BUTTON", L"ATRAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 345, 645, 150, 25, VentEmpleados, (HMENU)BTN_ATRAS6, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"IMPRIMIR EMPLEADOS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 530, 645, 170, 25, VentEmpleados, (HMENU)BTN_IMPRIMIR_EMPLEADOS, instancia, NULL);


            // Control estático y de edición para la cédula del empleado
            CreateWindowEx(0, L"STATIC", L"CÉDULA", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 70, 100, 25, VentEmpleados, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 140, 70, 200, 25, VentEmpleados, (HMENU)EDT_CEDULA_EMPLEADO, instancia, NULL);

            // Control estático y de edición para el número de empleado
            CreateWindowEx(0, L"STATIC", L"NÚMERO EMPLEADO", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 120, 150, 25, VentEmpleados, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 191, 120, 150, 25, VentEmpleados, (HMENU)EDT_NUMERO_EMPLEADO, instancia, NULL);

            // Control estático y de edición para el nombre del empleado
            CreateWindowEx(0, L"STATIC", L"NOMBRE", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 170, 100, 25, VentEmpleados, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 140, 170, 200, 25, VentEmpleados, (HMENU)EDT_NOMBRE_EMPLEADO, instancia, NULL);

            // Control estático y de edición para el apellido del empleado
            CreateWindowEx(0, L"STATIC", L"APELLIDO", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 220, 100, 25, VentEmpleados, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 140, 220, 200, 25, VentEmpleados, (HMENU)EDT_APELLIDO_EMPLEADO, instancia, NULL);

            // Control estático y de edición para la dirección del empleado
            CreateWindowEx(0, L"STATIC", L"DIRECCIÓN", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 270, 100, 25, VentEmpleados, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 140, 270, 200, 25, VentEmpleados, (HMENU)EDT_DIRECCION_EMPLEADO, instancia, NULL);

            // Control estático y de edición para el cargo del empleado
            CreateWindowEx(0, L"STATIC", L"CARGO", SS_CENTER | WS_CHILD | WS_VISIBLE, 400, 120, 100, 25, VentEmpleados, NULL, instancia, NULL);
            CreateWindowEx(0, L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 520, 120, 200, 500, VentEmpleados, (HMENU)EDT_CARGO_EMPLEADO, instancia, NULL);
            
            for(int i = 0; i < nItems; i++){
                SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_ADDSTRING, 0, (LPARAM)cargos[i]);
                SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_SETCURSEL, (WPARAM)3, (LPARAM)0);
            }


            // Control estático y de edición para el teléfono del empleado
            CreateWindowEx(0, L"STATIC", L"TELÉFONO", SS_CENTER | WS_CHILD | WS_VISIBLE, 400, 70, 100, 25, VentEmpleados, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 520, 70, 200, 25, VentEmpleados, (HMENU)EDT_TELEFONO_EMPLEADO, instancia, NULL);
             
            CreateWindowEx(0, L"BUTTON", L"GUARDAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 400, 250, 150, 45, VentEmpleados, (HMENU)BTN_GUARDAR_EMPLEADO, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"LIMPIAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 570, 250, 150, 45, VentEmpleados, (HMENU)BTN_LIMPIAR_EMPLEADO, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"BUSCAR EMPLEADO", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 490, 190, 150, 45, VentEmpleados, (HMENU)BTN_BUSCAR_EMPLEADO, instancia, NULL);



            ListViewEmpleado = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Empleados", WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING, 25, 320, 1000, 300, VentEmpleados, NULL, instancia, NULL);
            ListView_SetExtendedListViewStyle(ListViewEmpleado, LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);
            EmpleadosEnListView(ListViewEmpleado);
            break;


            
        }
 
        case WM_COMMAND:{
            switch(LOWORD(wParam)){

                case BTN_GUARDAR_EMPLEADO:{
                    if (GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_NUMERO_EMPLEADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_NOMBRE_EMPLEADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_APELLIDO_EMPLEADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_DIRECCION_EMPLEADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_TELEFONO_EMPLEADO)) == 0) {
                    MessageBox(VentEmpleados, L"Debe ingresar todos los campos", L"Error", MB_OK | MB_ICONERROR);
                    break;
                }

                    wchar_t buffer[200];

                    GetDlgItemText(VentEmpleados, EDT_CEDULA_EMPLEADO, buffer, 200);
                    d_empleados[cant_empleados].cedula_trabajador = _wtoi(buffer);

                    GetDlgItemText(VentEmpleados, EDT_NUMERO_EMPLEADO, buffer, 200);
                    d_empleados[cant_empleados].numero_empleado = _wtoi(buffer);
                    
                    GetDlgItemText(VentEmpleados, EDT_NOMBRE_EMPLEADO, buffer, 200);
                    wcscpy_s(d_empleados[cant_empleados].nombre, 50, buffer);

                    GetDlgItemText(VentEmpleados, EDT_APELLIDO_EMPLEADO, buffer, 200);
                    wcscpy_s(d_empleados[cant_empleados].apellido, 50, buffer);

                    GetDlgItemText(VentEmpleados, EDT_DIRECCION_EMPLEADO, buffer, 200);
                    wcscpy_s(d_empleados[cant_empleados].direccion, 100, buffer);

                    wchar_t cargo_seleccionado[256];
                    int indice_cargo = SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_GETCURSEL, 0,0);
                    if(indice_cargo != CB_ERR){    
                        SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_GETLBTEXT, indice_cargo, (LPARAM)cargo_seleccionado);
                        wcscpy_s(d_empleados[cant_empleados].cargo, 256, cargo_seleccionado);
                    }

                    d_empleados[cant_empleados].telefono = GetDlgItemInt(VentEmpleados, EDT_TELEFONO_EMPLEADO, NULL, FALSE);

                    FILE *archivo_empleados;
                    archivo_empleados = fopen("empleados.dat", "a");
                    if (archivo_empleados == NULL) {
                        MessageBox(VentEmpleados, L"ERROR", L"ERROR AL CREAR EL ARCHIVO", MB_OKCANCEL);
                        return 1;
                    }

                    fprintf(archivo_empleados, "Cedula: %d\n", d_empleados[cant_empleados].cedula_trabajador);
                    fprintf(archivo_empleados, "Numero Empleado: %d\n", d_empleados[cant_empleados].numero_empleado);
                    fprintf(archivo_empleados, "Nombre: %ls\n", d_empleados[cant_empleados].nombre);
                    fprintf(archivo_empleados, "Apellido: %ls\n", d_empleados[cant_empleados].apellido);
                    fprintf(archivo_empleados, "Direccion: %ls\n", d_empleados[cant_empleados].direccion);
                    fprintf(archivo_empleados, "Cargo: %ls\n", d_empleados[cant_empleados].cargo);
                    fprintf(archivo_empleados, "Telefono: %d\n", d_empleados[cant_empleados].telefono);
                    fprintf(archivo_empleados, "---------------------\n");

                    fclose(archivo_empleados);

                    cant_empleados++;
                    MessageBox(VentEmpleados, L"Empleado guardado exitosamente", L"Éxito", MB_OK);
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_NUMERO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_NOMBRE_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_APELLIDO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_DIRECCION_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_CARGO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_TELEFONO_EMPLEADO), L"");

                    DestroyWindow(VentEmpleados);

                    HWND nVentEmpleados = CreateWindowEx(0, L"CL_VentanaEmpleados", L"Empleados", WS_OVERLAPPEDWINDOW, 5,5,1080,720,NULL, NULL, instancia, NULL);
                      ShowWindow(nVentEmpleados, SW_SHOW);
                      UpdateWindow(nVentEmpleados);

                    break;
                }

                case BTN_BUSCAR_EMPLEADO:{
                   
                    if(GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO)) == 0){
                        MessageBox(VentEmpleados, L"Ingrese la cedula del empleado a buscar", L"Error", MB_ICONERROR |MB_OK);
                        break;
                    }

                    wchar_t buffer[100];
                    GetWindowText(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO), buffer, 100);
                    int cedula = _wtoi(buffer);

                    int empleadoEncontrado = 0;
                    for (int i = 0; i < cant_empleados; i++) {
                        if (cedula == d_empleados[i].cedula_trabajador) {
                            SetWindowText(GetDlgItem(VentEmpleados, EDT_NUMERO_EMPLEADO), buffer);
                            swprintf_s(buffer, 100, L"%d", d_empleados[i].numero_empleado);
                            SetWindowText(GetDlgItem(VentEmpleados, EDT_NUMERO_EMPLEADO), buffer);
                            SetWindowText(GetDlgItem(VentEmpleados, EDT_NOMBRE_EMPLEADO), d_empleados[i].nombre);
                            SetWindowText(GetDlgItem(VentEmpleados, EDT_APELLIDO_EMPLEADO), d_empleados[i].apellido);
                            SetWindowText(GetDlgItem(VentEmpleados, EDT_DIRECCION_EMPLEADO), d_empleados[i].direccion);
                            int index = SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_FINDSTRINGEXACT, -1, (LPARAM)d_empleados[i].cargo);
                            if (index != CB_ERR) {
                                SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_SETCURSEL, (WPARAM)index, 0);
                            }
                            swprintf_s(buffer, 100, L"%d", d_empleados[i].telefono);
                            SetWindowText(GetDlgItem(VentEmpleados, EDT_TELEFONO_EMPLEADO), buffer);
                            empleadoEncontrado = 1;
                            break;
                        }
                    }

                    if (!empleadoEncontrado) {
                        MessageBox(VentEmpleados, L"Empleado no encontrado", L"Error", MB_ICONERROR | MB_OK);
                    }

                    // Eliminar el botón de guardar si existe
                    HWND hGuardarButton = GetDlgItem(VentEmpleados, BTN_GUARDAR_EMPLEADO);
                    if (hGuardarButton) {
                        DestroyWindow(hGuardarButton);
                    }

                    // Eliminar el botón de limpiar si existe
                    HWND hLimpiarButton = GetDlgItem(VentEmpleados, BTN_LIMPIAR_EMPLEADO);
                    if (hLimpiarButton) {
                        DestroyWindow(hLimpiarButton);
                    }

                    // Crear botón de editar empleado
                    CreateWindowEx(0, L"BUTTON", L"EDITAR EMPLEADO", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 400, 250, 150, 45, VentEmpleados, (HMENU)BTN_EDITAR_EMPLEADO, instancia, NULL);

                    // Crear botón de eliminar empleado
                    CreateWindowEx(0, L"BUTTON", L"ELIMINAR EMPLEADO", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 570, 250, 150, 45, VentEmpleados, (HMENU)BTN_ELIMINAR_EMPLEADO, instancia, NULL);
 

                    break;
                }

                case BTN_EDITAR_EMPLEADO:{
                    if (GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_NUMERO_EMPLEADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_NOMBRE_EMPLEADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_APELLIDO_EMPLEADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_DIRECCION_EMPLEADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_TELEFONO_EMPLEADO)) == 0) {
                        MessageBox(VentEmpleados, L"Debe llenar todos los campos", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    wchar_t buffer[200];
                    int cedula_empleado;

                    // Obtener la cédula del empleado
                    GetWindowText(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO), buffer, 100);
                    cedula_empleado = _wtoi(buffer);

                    // Buscar el empleado en la estructura
                    int empleadoEncontrado = -1;
                    for (int i = 0; i < cant_empleados; i++) {
                        if (d_empleados[i].cedula_trabajador == cedula_empleado) {
                            empleadoEncontrado = i;
                            break;
                        }
                    }

                    if (empleadoEncontrado == -1) {
                        MessageBox(VentEmpleados, L"Empleado no encontrado", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    // Actualizar los datos del empleado en la estructura
                    GetDlgItemText(VentEmpleados, EDT_NUMERO_EMPLEADO, buffer, 200);
                    d_empleados[empleadoEncontrado].numero_empleado = _wtoi(buffer);

                    GetDlgItemText(VentEmpleados, EDT_NOMBRE_EMPLEADO, buffer, 200);
                    wcscpy_s(d_empleados[empleadoEncontrado].nombre, 50, buffer);

                    GetDlgItemText(VentEmpleados, EDT_APELLIDO_EMPLEADO, buffer, 200);
                    wcscpy_s(d_empleados[empleadoEncontrado].apellido, 50, buffer);

                    GetDlgItemText(VentEmpleados, EDT_DIRECCION_EMPLEADO, buffer, 200);
                    wcscpy_s(d_empleados[empleadoEncontrado].direccion, 100, buffer);

                    wchar_t cargo_seleccionado[256];
                    int indice_cargo = SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_GETCURSEL, 0, 0);
                    if (indice_cargo != CB_ERR) {
                        SendDlgItemMessage(VentEmpleados, EDT_CARGO_EMPLEADO, CB_GETLBTEXT, indice_cargo, (LPARAM)cargo_seleccionado);
                        wcscpy_s(d_empleados[empleadoEncontrado].cargo, 256, cargo_seleccionado);
                    }

                    d_empleados[empleadoEncontrado].telefono = GetDlgItemInt(VentEmpleados, EDT_TELEFONO_EMPLEADO, NULL, FALSE);

                    // Actualizar el archivo de empleados
                    FILE *archivo_empleados = fopen("empleados.dat", "w");
                    if (archivo_empleados == NULL) {
                        MessageBox(VentEmpleados, L"Error al abrir el archivo de empleados", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    for (int i = 0; i < cant_empleados; i++) {
                        fprintf(archivo_empleados, "Cedula: %d\n", d_empleados[i].cedula_trabajador);
                        fprintf(archivo_empleados, "Numero Empleado: %d\n", d_empleados[i].numero_empleado);
                        fprintf(archivo_empleados, "Nombre: %ls\n", d_empleados[i].nombre);
                        fprintf(archivo_empleados, "Apellido: %ls\n", d_empleados[i].apellido);
                        fprintf(archivo_empleados, "Direccion: %ls\n", d_empleados[i].direccion);
                        fprintf(archivo_empleados, "Cargo: %ls\n", d_empleados[i].cargo);
                        fprintf(archivo_empleados, "Telefono: %d\n", d_empleados[i].telefono);
                        fprintf(archivo_empleados, "---------------------\n");
                    }

                    fclose(archivo_empleados);

                    MessageBox(VentEmpleados, L"Empleado editado exitosamente", L"Éxito", MB_OK);

                    // Limpiar los campos de entrada
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_NUMERO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_NOMBRE_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_APELLIDO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_DIRECCION_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_CARGO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_TELEFONO_EMPLEADO), L"");

                    // Actualizar la vista de la lista de empleados
                    DestroyWindow(VentEmpleados);
                    HWND nVentEmpleados = CreateWindowEx(0, L"CL_VentanaEmpleados", L"Empleados", WS_OVERLAPPEDWINDOW, 5, 5, 1080, 720, NULL, NULL, instancia, NULL);
                    ShowWindow(nVentEmpleados, SW_SHOW);
                    UpdateWindow(nVentEmpleados);

                    break;
                }

                case BTN_ELIMINAR_EMPLEADO:{
                    if (GetWindowTextLength(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO)) == 0) {
                        MessageBox(VentEmpleados, L"Debe ingresar la cédula del empleado para eliminar", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    wchar_t buffer[100];
                    GetWindowText(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO), buffer, 100);
                    int cedula_empleado = _wtoi(buffer);

                    // Buscar el empleado en la estructura
                    int empleadoEncontrado = -1;
                    for (int i = 0; i < cant_empleados; i++) {
                        if (d_empleados[i].cedula_trabajador == cedula_empleado) {
                            empleadoEncontrado = i;
                            break;
                        }
                    }

                    if (empleadoEncontrado == -1) {
                        MessageBox(VentEmpleados, L"Empleado no encontrado", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    // Eliminar el empleado de la estructura
                    for (int i = empleadoEncontrado; i < cant_empleados - 1; i++) {
                        d_empleados[i] = d_empleados[i + 1];
                    }
                    cant_empleados--;

                    // Actualizar el archivo de empleados
                    FILE *archivo_empleados = fopen("empleados.dat", "w");
                    if (archivo_empleados == NULL) {
                        MessageBox(VentEmpleados, L"Error al abrir el archivo de empleados", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    for (int i = 0; i < cant_empleados; i++) {
                        fprintf(archivo_empleados, "Cedula: %d\n", d_empleados[i].cedula_trabajador);
                        fprintf(archivo_empleados, "Numero Empleado: %d\n", d_empleados[i].numero_empleado);
                        fprintf(archivo_empleados, "Nombre: %ls\n", d_empleados[i].nombre);
                        fprintf(archivo_empleados, "Apellido: %ls\n", d_empleados[i].apellido);
                        fprintf(archivo_empleados, "Direccion: %ls\n", d_empleados[i].direccion);
                        fprintf(archivo_empleados, "Cargo: %ls\n", d_empleados[i].cargo);
                        fprintf(archivo_empleados, "Telefono: %d\n", d_empleados[i].telefono);
                        fprintf(archivo_empleados, "---------------------\n");
                    }

                    fclose(archivo_empleados);

                    MessageBox(VentEmpleados, L"Empleado eliminado exitosamente", L"Éxito", MB_OK);

                    // Limpiar los campos de entrada
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_CEDULA_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_NUMERO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_NOMBRE_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_APELLIDO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_DIRECCION_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_CARGO_EMPLEADO), L"");
                    SetWindowText(GetDlgItem(VentEmpleados, EDT_TELEFONO_EMPLEADO), L"");

                    // Actualizar la vista de la lista de empleados
                    DestroyWindow(VentEmpleados);
                    HWND nVentEmpleados = CreateWindowEx(0, L"CL_VentanaEmpleados", L"Empleados", WS_OVERLAPPEDWINDOW, 5, 5, 1080, 720, NULL, NULL, instancia, NULL);
                    ShowWindow(nVentEmpleados, SW_SHOW);
                    UpdateWindow(nVentEmpleados);

                    break;
                }

                case BTN_IMPRIMIR_EMPLEADOS:{

                    FILE *archivo_cvs = fopen("ReporteEmpleados.csv", "w");
                    if (archivo_cvs == NULL) {
                        MessageBox(VentEmpleados, L"Error al crear el archivo cvs", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    // Escribir encabezados
                    fwprintf(archivo_cvs, L"Cedula; Numero Empleado; Nombre; Apellido; Direccion; Cargo; Telefono\n");

                    // Escribir datos de empleados
                    for (int i = 0; i < cant_empleados; i++) {
                        fwprintf(archivo_cvs, L"%d;%d;%ls;%ls;%ls;%ls;%d\n",
                                 d_empleados[i].cedula_trabajador,
                                 d_empleados[i].numero_empleado,
                                 d_empleados[i].nombre,
                                 d_empleados[i].apellido,
                                 d_empleados[i].direccion,
                                 d_empleados[i].cargo,
                                 d_empleados[i].telefono);
                    }

                    fclose(archivo_cvs);
                    MessageBox(VentEmpleados, L"Empleados exportados a ReporteEmpleados.csv exitosamente", L"Éxito", MB_OK);

                    break;
                }

                case BTN_ATRAS6:{
                    DestroyWindow(VentEmpleados);

                    break;
                }
            }


            break;
        }

        default:{

           return DefWindowProc(VentEmpleados, msg, wParam, lParam);
         
        } 

    }

    return 0;
}

LRESULT CALLBACK VentanaFacturas(HWND VentFacturas, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HINSTANCE instancia;

    switch (msg) {
        case WM_CREATE: {
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;

            CreateWindowEx(0, L"BUTTON", L"CREAR FACTURA", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 100, 100, 200, 25, VentFacturas, (HMENU)BTN_CREAR_FACTURA, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"MOSTRAR FACTURA", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 100, 150, 200, 25, VentFacturas, (HMENU)BTN_LISTA_FACTURA, instancia, NULL);
            
            break;
        }

        case WM_COMMAND:{
            switch(LOWORD(wParam)){
                case BTN_CREAR_FACTURA:{
                    DestroyWindow(VentFacturas);
                    HWND VentCrearFactura = CreateWindowEx(0, L"CL_VentanaCrearFactura", L"CREAR FACTURA", WS_OVERLAPPEDWINDOW, 20, 5, 1180, 760, NULL, NULL, instancia, NULL);
                    ShowWindow(VentCrearFactura, SW_SHOW);
                    UpdateWindow(VentCrearFactura);
                    break;
                }

                case BTN_LISTA_FACTURA:{
                    DestroyWindow(VentFacturas);
                    HWND VentMostrarFactura = CreateWindowEx(0, L"CL_VentanaMostrarFactura", L"MOSTRAR FACTURA", WS_OVERLAPPEDWINDOW, 10, 10, 1020, 700, NULL, NULL, instancia, NULL);
                    ShowWindow(VentMostrarFactura, SW_SHOW);
                    UpdateWindow(VentMostrarFactura);
                    break;
                }
            }


            break;
        }


        case WM_CLOSE: {
            DestroyWindow(VentFacturas);
            break;
        }

        default: {
            return DefWindowProc(VentFacturas, msg, wParam, lParam);
        }
    }

    return 0;
}

LRESULT CALLBACK VentanaCrearFactura(HWND VentCrearFacturas, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HINSTANCE instancia;
    HWND hListViewProductos, hListViewFactura, hEditFecha;


    switch(msg){
        case WM_CREATE: {
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;
       
            { 
            // ====================================================
            // IZQUIERDA: Creación de la Factura
            // ====================================================
            
            // Grupo: Datos del Cliente
            CreateWindowEx(0, L"BUTTON", L"Datos del Cliente", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 20, 20, 560, 260, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"BUSCAR CLIENTE", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 380, 40, 150, 25, VentCrearFacturas, (HMENU)BTN_BUSCAR_CLIENTE, instancia, NULL);

            // CÉDULA CLIENTE
            CreateWindowEx(0, L"STATIC", L"CÉDULA CLIENTE", SS_RIGHT | WS_CHILD | WS_VISIBLE, 40, 40, 120, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 170, 40, 200, 25, VentCrearFacturas, (HMENU)EDT_CEDULA_FACTURA, instancia, NULL);
            
            // NOMBRE
            CreateWindowEx(0, L"STATIC", L"NOMBRE", SS_RIGHT | WS_CHILD | WS_VISIBLE, 40, 80, 120, 25,VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 170, 80, 200, 25, VentCrearFacturas, (HMENU)EDT_NOMBRE_FACTURA, instancia, NULL);
            
            // APELLIDO
            CreateWindowEx(0, L"STATIC", L"APELLIDO", SS_RIGHT | WS_CHILD | WS_VISIBLE, 40, 120, 120, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 170, 120, 200, 25, VentCrearFacturas, (HMENU)EDT_APELLIDO_FACTURA, instancia, NULL);
            
            // DIRECCIÓN
            CreateWindowEx(0, L"STATIC", L"DIRECCIÓN", SS_RIGHT | WS_CHILD | WS_VISIBLE, 40, 160, 120, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 170, 160, 200, 25, VentCrearFacturas, (HMENU)EDT_DIRECCION_FACTURA, instancia, NULL);
            
            // TELÉFONO
            CreateWindowEx(0, L"STATIC", L"TELÉFONO", SS_RIGHT | WS_CHILD | WS_VISIBLE, 40, 200, 120, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 170, 200, 200, 25, VentCrearFacturas, (HMENU)EDT_TELEFONO_FACTURA, instancia, NULL);
            
            // Grupo: Productos Disponibles
            CreateWindowEx(0, L"BUTTON", L"Productos Disponibles", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 20, 300, 560, 240, VentCrearFacturas, NULL, instancia, NULL);
            
            // ListView para mostrar los productos disponibles
            hListViewProductos = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Productos",  WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING, 40, 330, 520, 200, VentCrearFacturas, NULL, instancia, NULL);
            ListView_SetExtendedListViewStyle(hListViewProductos, LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);
            ProductosEnListView(hListViewProductos);
            
            // Controles para agregar producto 
            CreateWindowEx(0, L"STATIC", L"CANTIDAD", SS_RIGHT | WS_CHILD | WS_VISIBLE,  40, 570, 120, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 170, 570, 200, 25, VentCrearFacturas, (HMENU)EDT_CANTIDAD_PRODUCTO_FACTURA, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"AGREGAR PRODUCTO",  BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 380, 568, 150, 60, VentCrearFacturas, (HMENU)EDT_AGREGAR_PRODUCTO_FACTURA, instancia, NULL);
            
          
            // CÓDIGO PRODUCTO
            CreateWindowEx(0, L"STATIC", L"CÓDIGO", SS_RIGHT | WS_CHILD | WS_VISIBLE, 40, 600, 120, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 170, 600, 200, 25, VentCrearFacturas, (HMENU)EDT_CODIGO_PRODUCTO_FACTURA, instancia, NULL);
  
            // ====================================================
            // DERECHA: Información de la Factura (Resumen)
            // ====================================================
            
            CreateWindowEx(0, L"BUTTON", L"Información de Factura", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 600, 20, 460, 680, VentCrearFacturas, NULL, instancia, NULL);
            
            // ID Hipermercado
            CreateWindowEx(0, L"STATIC", L"ID Hipermercado:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 50, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"J-12345678-9", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 780, 50, 200, 25, VentCrearFacturas, (HMENU)EDT_ID_HIPERMERCADO, instancia, NULL);
            
            // Número de Factura
            CreateWindowEx(0, L"STATIC", L"Número Factura:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 90, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 780, 90, 200, 25, VentCrearFacturas, (HMENU)EDT_NUMERO_FACTURA, instancia, NULL);
          
            
            // Fecha
            CreateWindowEx(0, L"STATIC", L"Fecha:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 130, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            hEditFecha = CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 780, 130, 200, 25, VentCrearFacturas, (HMENU)EDT_FECHA_FACTURA, instancia, NULL);
            wchar_t buffer[100];
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            swprintf_s(buffer, 100, L"%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            SetWindowText(hEditFecha, buffer);

            // Cliente (datos del cliente)
            CreateWindowEx(0, L"STATIC", L"Cliente:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 170, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 780, 170, 200, 25, VentCrearFacturas, (HMENU)EDT_CLIENTE_FACTURA, instancia, NULL);
            
            // Compra: Aquí se mostrará el detalle de los productos agregados (resumen de la factura)
            CreateWindowEx(0, L"STATIC", L"Compra:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 210, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
          hListViewFactura = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Compra", WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING, 620, 240, 360, 150, VentCrearFacturas, NULL, instancia, NULL);
            ListView_SetExtendedListViewStyle(hListViewFactura, LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);

            // Agregar columnas al ListView de la factura
            LVCOLUMN col = {0};
            col.mask = LVCF_TEXT | LVCF_WIDTH;

            // Primera columna: "Producto"
            col.pszText = L"Producto";
            col.cx = 150; // ancho en píxeles
            ListView_InsertColumn(hListViewFactura, 0, &col);

            // Segunda columna: "Cantidad"
            col.pszText = L"Cantidad";
            col.cx = 100;
            ListView_InsertColumn(hListViewFactura, 1, &col);

            // Tercera columna: "Precio Unitario"
            col.pszText = L"Precio Unitario";
            col.cx = 100;
            ListView_InsertColumn(hListViewFactura, 2, &col);


            // Pago Bruto
            CreateWindowEx(0, L"STATIC", L"Pago Bruto $:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 400, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 780, 400, 65, 25, VentCrearFacturas, (HMENU)EDT_PAGO_BRUTO, instancia, NULL);
            
            // Porcentaje IVA
            CreateWindowEx(0, L"STATIC", L"Porcentaje IVA:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 440, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,780, 440, 65, 25, VentCrearFacturas, (HMENU)EDT_PORCENTAJE_IVA, instancia, NULL);
            
            // Pago Total
            CreateWindowEx(0, L"STATIC", L"Pago Total$:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 480, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 780, 480, 65, 25, VentCrearFacturas, (HMENU)EDT_PAGO_TOTAL, instancia, NULL);
            
            CreateWindowEx(0, L"STATIC", L"BS:", SS_LEFT | WS_CHILD | WS_VISIBLE, 865, 400, 30, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,900, 400, 65, 25, VentCrearFacturas, (HMENU)EDT_PAGO_BRUTOBS, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"BS:", SS_LEFT | WS_CHILD | WS_VISIBLE, 865, 480, 30, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,900, 480, 65, 25, VentCrearFacturas, (HMENU)EDT_PAGO_TOTALBS, instancia, NULL);

            // Checkpoint 1: Forma de Pago en dolares
            CreateWindowEx(0, L"BUTTON", L"Pago $", BS_AUTORADIOBUTTON | WS_GROUP | WS_CHILD | WS_VISIBLE, 850, 510, 75, 25, VentCrearFacturas, (HMENU)IDC_CHECK_DOL, instancia, NULL);

            // Checkpoint 2: Forma de Pago en bolivares
            CreateWindowEx(0, L"BUTTON", L"Pago Bs", BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE, 850, 540, 75, 25, VentCrearFacturas, (HMENU)IDC_CHECK_BS, instancia, NULL);

            // Checkpoint 3: Forma de pago en euros
            CreateWindowEx(0, L"BUTTON", L"Pago EUR", BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE, 950, 510, 85, 25, VentCrearFacturas, (HMENU)IDC_CHECK_EUR, instancia, NULL);

            // Checkpoint 4: Forma de pago en pesos
            CreateWindowEx(0, L"BUTTON", L"Pago PES", BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE, 950, 540, 85, 25, VentCrearFacturas, (HMENU)IDC_CHECK_PES, instancia, NULL);

            // Información de Caja (por ejemplo, el número de caja)
            CreateWindowEx(0, L"STATIC", L"Caja:", SS_LEFT | WS_CHILD | WS_VISIBLE, 620, 520, 150, 25, VentCrearFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"",ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 780, 520, 65, 25, VentCrearFacturas, (HMENU)EDT_CAJA_FACTURA, instancia, NULL);
            
            // Botones dentro del groupbox de Información de Factura
            CreateWindowEx(0, L"BUTTON", L"IMPRIMIR FACTURA", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 660, 570, 150, 30, VentCrearFacturas, (HMENU)BTN_IMPRIMIR_FACTURA, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"CERRAR", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 750, 625, 150, 30, VentCrearFacturas, (HMENU)BTN_CERRAR_FACTURA, instancia, NULL);
             
            // Botón para guardar la factura
            CreateWindowEx(0, L"BUTTON", L"GUARDAR FACTURA", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 830, 570, 150, 30, VentCrearFacturas, (HMENU)BTN_GUARDAR_FACTURA, instancia, NULL);
            }
            
            
            break;
        }
    
        case WM_COMMAND:{      
            switch(LOWORD(wParam)){
                    case BTN_BUSCAR_CLIENTE: {
                        if (GetWindowTextLength(GetDlgItem(VentCrearFacturas, EDT_CEDULA_FACTURA)) == 0) {
                            MessageBox(VentCrearFacturas, L"Debe llenar el campo cédula para buscar", L"Error", MB_ICONERROR | MB_OK);
                            break;
                        }

                        wchar_t buffer[100];
                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_CEDULA_FACTURA), buffer, 100);
                        int cedula = _wtoi(buffer);

                        int clienteEncontrado = 0;

                        for (int i = 0; i < cant_clientes; i++) {
                            if (cedula == d_clientes[i].cedula) {
                                SetWindowText(GetDlgItem(VentCrearFacturas, EDT_NOMBRE_FACTURA), d_clientes[i].nombre);
                                SetWindowText(GetDlgItem(VentCrearFacturas, EDT_APELLIDO_FACTURA), d_clientes[i].apellido);
                                SetWindowText(GetDlgItem(VentCrearFacturas, EDT_DIRECCION_FACTURA), d_clientes[i].direccion);
                                swprintf_s(buffer, 100, L"%d", d_clientes[i].telefono);
                                SetWindowText(GetDlgItem(VentCrearFacturas, EDT_TELEFONO_FACTURA), buffer);

                                swprintf_s(buffer, 100, L"%s %s", d_clientes[i].nombre, d_clientes[i].apellido);
                                SetWindowText(GetDlgItem(VentCrearFacturas, EDT_CLIENTE_FACTURA), buffer);

                                clienteEncontrado = 1;
                                break;
                            }
                        }

                        if (!clienteEncontrado) {
                            MessageBox(VentCrearFacturas, L"Cliente no encontrado. Ingrese los datos del cliente.", L"Información", MB_OK | MB_ICONINFORMATION);
                            SetWindowText(GetDlgItem(VentCrearFacturas, EDT_NOMBRE_FACTURA), L"");
                            SetWindowText(GetDlgItem(VentCrearFacturas, EDT_APELLIDO_FACTURA), L"");
                            SetWindowText(GetDlgItem(VentCrearFacturas, EDT_DIRECCION_FACTURA), L"");
                            SetWindowText(GetDlgItem(VentCrearFacturas, EDT_TELEFONO_FACTURA), L"");
                        }
                        break;

                
                    }

                    case EDT_AGREGAR_PRODUCTO_FACTURA:{
                        wchar_t buffer[128];
                        // Obtener el código del producto ingresado
                        GetDlgItemText(VentCrearFacturas, EDT_CODIGO_PRODUCTO_FACTURA, buffer, 128);
                        int codigo = _wtoi(buffer);
                        
                        // Obtener la cantidad a agregar
                        GetDlgItemText(VentCrearFacturas, EDT_CANTIDAD_PRODUCTO_FACTURA, buffer, 128);
                        int cantidad_a_agregar = _wtoi(buffer);
                        
                        if(cantidad_a_agregar <= 0) {
                            MessageBox(VentCrearFacturas, L"Cantidad inválida", L"Error", MB_ICONERROR);
                            break;
                        }
                        
                        // Buscar el producto por código
                        int index = -1;
                        for (int i = 0; i < cant_productos; i++) {
                            if(d_productos[i].codigo == codigo) {
                                index = i;
                                break;
                            }
                        }
                        
                        if (index == -1) {
                            MessageBox(VentCrearFacturas, L"Producto no encontrado", L"Error", MB_ICONERROR);
                            break;
                        }
                        
                        // Verificar que exista stock suficiente
                        if(d_productos[index].cantidad_disponible < cantidad_a_agregar) {
                            MessageBox(VentCrearFacturas, L"Cantidad insuficiente en inventario", L"Error", MB_ICONERROR);
                            break;
                        }
                        
                        // Calcular subtotal usando el precio en dólares (por ejemplificar)
                        float unit_price = d_productos[index].precioDOL;
                        float subtotal = unit_price * cantidad_a_agregar;
                        
                        // Agregar el producto al ListView de la factura
                        HWND hListViewFactura = FindWindowEx(VentCrearFacturas, NULL, WC_LISTVIEW, L"Compra");
                        if(hListViewFactura == NULL) {
                            MessageBox(VentCrearFacturas, L"ListView de factura no encontrado", L"Error", MB_ICONERROR);
                            break;
                        }
                        
                        LVITEM lvItem = {0};
                        lvItem.mask = LVIF_TEXT;
                        int itemCount = ListView_GetItemCount(hListViewFactura);
                        lvItem.iItem = itemCount;
                        // Columna 0: Nombre del producto
                        lvItem.pszText = d_productos[index].nombre_producto;
                        int listIndex = ListView_InsertItem(hListViewFactura, &lvItem);
                    
                        // Columna 1: Cantidad
                        swprintf_s(buffer, 128, L"%d", cantidad_a_agregar);
                        ListView_SetItemText(hListViewFactura, listIndex, 1, buffer);
                    
                        // Columna 2: Precio Unitario
                        swprintf_s(buffer, 128, L"%.2f", unit_price);
                        ListView_SetItemText(hListViewFactura, listIndex, 2, buffer);
                        
                        // Actualizar totales de la factura
                        // Leer el pago bruto actual
                        float pago_bruto = 0;
                        GetDlgItemText(VentCrearFacturas, EDT_PAGO_BRUTO, buffer, 128);
                        pago_bruto = (float)_wtof(buffer);
                        pago_bruto += subtotal;
                        swprintf_s(buffer, 128, L"%.2f", pago_bruto);
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_BRUTO), buffer);
                        
                        // IVA definido (por ejemplo, 0.16)
                        float porcentajeIVA = IVA;
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PORCENTAJE_IVA), L"0.16");
                        
                        float pago_total = pago_bruto * (1 + porcentajeIVA);
                        swprintf_s(buffer, 128, L"%.2f", pago_total);
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_TOTAL), buffer);
                        float pago_brutobs = pago_bruto * TASA_BS;
                        swprintf_s(buffer, 128, L"%.2f", pago_brutobs);
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_BRUTOBS), buffer);

                        float pago_totalbs = pago_total * TASA_BS;
                        swprintf_s(buffer, 128, L"%.2f", pago_totalbs);
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_TOTALBS), buffer);
                        
                        // Restar la cantidad vendida en la estructura
                        d_productos[index].cantidad_disponible -= cantidad_a_agregar;
                        
                        // Actualizar el archivo de productos reescribiendo todos los registros
                        FILE *archivo_productos = fopen("productos.dat", "w");
                        if(archivo_productos != NULL) {
                            for (int i = 0; i < cant_productos; i++) {
                                fprintf(archivo_productos, "ID: %i\n", i);
                                fprintf(archivo_productos, "Codigo: %d\n", d_productos[i].codigo);
                                fprintf(archivo_productos, "Nombre Producto: %ls\n", d_productos[i].nombre_producto);
                                fprintf(archivo_productos, "Cantidad Disponible: %d\n", d_productos[i].cantidad_disponible);
                                fprintf(archivo_productos, "Precio Dolar: %.2f\n", d_productos[i].precioDOL);
                                fprintf(archivo_productos, "Precio Bolivares: %.2f\n", d_productos[i].precioBS);
                                fprintf(archivo_productos, "Precio Euros: %.2f\n", d_productos[i].precioEUR);
                                fprintf(archivo_productos, "Precio Pesos: %.2f\n", d_productos[i].precioPES);
                                fprintf(archivo_productos, "---------------------\n");
                            }
                            fclose(archivo_productos);
                        } else {
                            MessageBox(VentCrearFacturas, L"Error al actualizar archivo de productos", L"Error", MB_ICONERROR);
                        }
                        
                        // Limpiar los campos de entrada para el producto
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_CODIGO_PRODUCTO_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_CANTIDAD_PRODUCTO_FACTURA), L"");

                        // Obtener el número de factura actual
                        int numFacturaActual = cant_facturas + 1;
                        // Verificar si el campo EDT_NUMERO_FACTURA está vacío
                        if (GetWindowTextLength(GetDlgItem(VentCrearFacturas, EDT_NUMERO_FACTURA)) == 0) {
                            // Si está vacío, establecer el número de factura
                            swprintf_s(buffer, 128, L"%d", numFacturaActual);
                            SetWindowText(GetDlgItem(VentCrearFacturas, EDT_NUMERO_FACTURA), buffer);
                        }
                        
                        
                        break;
                    }
                    
                    case BTN_GUARDAR_FACTURA:{
                        wchar_t buffer[128];

                        // Verificar que los campos esenciales no estén vacíos
                        if (GetWindowTextLength(GetDlgItem(VentCrearFacturas, EDT_CEDULA_FACTURA)) == 0 ||
                            GetWindowTextLength(GetDlgItem(VentCrearFacturas, EDT_NOMBRE_FACTURA)) == 0 ||
                            GetWindowTextLength(GetDlgItem(VentCrearFacturas, EDT_PAGO_BRUTO)) == 0 ||
                            GetWindowTextLength(GetDlgItem(VentCrearFacturas, EDT_CAJA_FACTURA)) == 0)
                        {
                            MessageBox(VentCrearFacturas, L"Faltan campos obligatorios", L"Error", MB_ICONERROR);
                            break;
                        }
                    
                        // Construir la factura
                        datos_facturas factura = {0};
                    
                        // Obtener el identificador del hipermercado (control de solo lectura)
                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_ID_HIPERMERCADO), factura.ID_hipermercado, 15);
                    
                        // Asignar número de factura (puede usar un contador: cant_facturas + 1)
                        factura.numero_factura = cant_facturas + 1;
                    
                        // Fecha (control de solo lectura)
                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_FECHA_FACTURA), factura.fecha, 20);
                    
                        // Datos del Cliente
                        {
                            wchar_t temp[100];
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_CEDULA_FACTURA), temp, 100);
                            factura.cliente.cedula = _wtoi(temp);
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_NOMBRE_FACTURA), factura.cliente.nombre, 150);
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_APELLIDO_FACTURA), factura.cliente.apellido, 150);
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_DIRECCION_FACTURA), factura.cliente.direccion, 200);
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_TELEFONO_FACTURA), temp, 100);
                            factura.cliente.telefono = _wtoi(temp);
                    
                            // Incrementar la cantidad de compras del cliente en la estructura global
                            for (int i = 0; i < cant_clientes; i++) {
                                if (d_clientes[i].cedula == factura.cliente.cedula) {
                                    d_clientes[i].cantidad_compras++;
                                    break;
                                }
                            }
                        }
                    
                        // Recopilar información de los productos agregados
                        {
                            HWND hFactList = FindWindowEx(VentCrearFacturas, NULL, WC_LISTVIEW, L"Compra");
                            if (hFactList == NULL) {
                                MessageBox(VentCrearFacturas, L"ListView de factura no encontrado", L"Error", MB_ICONERROR);
                                break;
                            }
                    
                            wchar_t prodDetalle[500] = L"";
                            wchar_t itemText[128] = L"";
                            int count = ListView_GetItemCount(hFactList);
                            for (int i = 0; i < count; i++) {
                                // Obtener nombre del producto (columna 0)
                                ListView_GetItemText(hFactList, i, 0, itemText, 128);
                                wcscat_s(prodDetalle, 500, itemText);
                                wcscat_s(prodDetalle, 500, L" x ");
                                // Obtener cantidad (columna 1)
                                ListView_GetItemText(hFactList, i, 1, itemText, 128);
                                wcscat_s(prodDetalle, 500, itemText);
                                wcscat_s(prodDetalle, 500, L", ");
                            }
                            wcscpy_s(factura.productos_comprados, 500, prodDetalle);
                        }
                    
                        // Totales de la factura
                        {
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_BRUTO), buffer, 128);
                            factura.pago_bruto = (float)_wtof(buffer);
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_PORCENTAJE_IVA), buffer, 128);
                            factura.porcentajeIVA = (float)_wtof(buffer);
                            GetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_TOTAL), buffer, 128);
                            factura.pago_total = (float)_wtof(buffer);
                        }
                    
                        // Procesar la Caja y determinar el método de pago
                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_CAJA_FACTURA), buffer, 128);
                        int numCaja = _wtoi(buffer);
                        int cajaIndex = -1;
                        for (int i = 0; i < cant_cajas; i++) {
                            if (d_cajas[i].numero_caja == numCaja) {
                                cajaIndex = i;
                                break;
                            }
                        }
                        if (cajaIndex == -1) {
                            MessageBox(VentCrearFacturas, L"Caja no encontrada", L"Error", MB_ICONERROR);
                            break;
                        }
                    
                        // Determinar el método de pago según el botón de radio seleccionado
                        wchar_t metodo_pago[20] = L"";
                        if (IsDlgButtonChecked(VentCrearFacturas, IDC_CHECK_BS) == BST_CHECKED) {
                            wcscpy_s(metodo_pago, 20, L"Bs");
                            d_cajas[cajaIndex].bolivares_facturados += factura.pago_bruto * TASA_BS;
                        }
                        else if (IsDlgButtonChecked(VentCrearFacturas, IDC_CHECK_DOL) == BST_CHECKED) {
                            wcscpy_s(metodo_pago, 20, L"$");
                            d_cajas[cajaIndex].dolares_facturados += factura.pago_bruto;
                        }
                        else if (IsDlgButtonChecked(VentCrearFacturas, IDC_CHECK_EUR) == BST_CHECKED) {
                            wcscpy_s(metodo_pago, 20, L"EUR");
                            d_cajas[cajaIndex].euros_facturados += factura.pago_bruto * TASA_EUR;
                        }
                        else if (IsDlgButtonChecked(VentCrearFacturas, IDC_CHECK_PES) == BST_CHECKED) {
                            wcscpy_s(metodo_pago, 20, L"PES");
                            d_cajas[cajaIndex].pesos_facturados += factura.pago_bruto * TASA_PES;
                        }
                        else {
                            MessageBox(VentCrearFacturas, L"Debe seleccionar un metodo de pago", L"Error", MB_ICONERROR | MB_OK);
                            break;
                        }
                        factura.caja = d_cajas[cajaIndex];
                    
                        // Guardar la factura en el arreglo global
                        d_facturas[cant_facturas] = factura;
                        cant_facturas++;
                    
                        float pago_bruto_convertido = factura.pago_bruto;
                        float pago_total_convertido = factura.pago_total;
                        if (wcscmp(metodo_pago, L"Bs") == 0) {
                            pago_bruto_convertido = factura.pago_bruto * TASA_BS;
                            pago_total_convertido = factura.pago_total * TASA_BS;
                        } else if (wcscmp(metodo_pago, L"EUR") == 0) {
                            pago_bruto_convertido = factura.pago_bruto * TASA_EUR;
                            pago_total_convertido = factura.pago_total * TASA_EUR;
                        } else if (wcscmp(metodo_pago, L"PES") == 0) {
                            pago_bruto_convertido = factura.pago_bruto * TASA_PES;
                            pago_total_convertido = factura.pago_total * TASA_PES;
                        }
                        
                        // Guardar la factura en el archivo "facturas.dat" (modo append)
                        FILE *archivo_facturas = fopen("facturas.dat", "a");
                        if (archivo_facturas != NULL) {
                            fprintf(archivo_facturas, "ID Hipermercado: %ls\n", factura.ID_hipermercado);
                            fprintf(archivo_facturas, "Número Factura: %d\n", factura.numero_factura);
                            fprintf(archivo_facturas, "Fecha: %ls\n", factura.fecha);
                            fprintf(archivo_facturas, "Cliente: %d %ls %ls, %ls, Tel: %d\n",
                                    factura.cliente.cedula, factura.cliente.nombre,
                                    factura.cliente.apellido, factura.cliente.direccion,
                                    factura.cliente.telefono);
                            fprintf(archivo_facturas, "Productos Comprados:\n%ls\n", factura.productos_comprados);
                            fprintf(archivo_facturas, "Pago Bruto (%ls): %.2f\n", metodo_pago, pago_bruto_convertido);
                            fprintf(archivo_facturas, "Porcentaje IVA: %.2f\n", factura.porcentajeIVA);
                            fprintf(archivo_facturas, "Pago Total (%ls): %.2f\n", metodo_pago, pago_total_convertido);
                            fprintf(archivo_facturas, "Caja: %d\n", factura.caja.numero_caja);
                            fprintf(archivo_facturas, "Método de pago: %ls\n", metodo_pago);
                            fprintf(archivo_facturas, "---------------------\n");
                            fclose(archivo_facturas);
                        } else {
                            MessageBox(VentCrearFacturas, L"Error al guardar factura", L"Error", MB_ICONERROR);
                            break;
                        }
                    
                        FILE *archivo_cajas = fopen("cajas.dat", "w");
                if (archivo_cajas != NULL) {
                    for (int i = 0; i < cant_cajas; i++) {
                        fprintf(archivo_cajas, "Numero Caja: %d\n", d_cajas[i].numero_caja);
                        // Se guardan los montos acumulados en cada moneda sin depender de la selección de transacción
                        fprintf(archivo_cajas, "Monto Facturado en Bs.: %.2f\n", d_cajas[i].bolivares_facturados);
                        fprintf(archivo_cajas, "Monto Facturado en $: %.2f\n", d_cajas[i].dolares_facturados);
                        fprintf(archivo_cajas, "Monto Facturado en EUR: %.2f\n", d_cajas[i].euros_facturados);
                        fprintf(archivo_cajas, "Monto Facturado en PES: %.2f\n", d_cajas[i].pesos_facturados);
                        fprintf(archivo_cajas, "Cedula Encargado: %d\n", d_cajas[i].encargador.cedula_trabajador);
                        fprintf(archivo_cajas, "Nombre Encargado: %ls\n", d_cajas[i].encargador.nombre);
                        fprintf(archivo_cajas, "Apellido Encargado: %ls\n", d_cajas[i].encargador.apellido);
                        fprintf(archivo_cajas, "Direccion Encargado: %ls\n", d_cajas[i].encargador.direccion);
                        fprintf(archivo_cajas, "Telefono Encargado: %d\n", d_cajas[i].encargador.telefono);
                        fprintf(archivo_cajas, "---------------------\n");
                    }
                    fclose(archivo_cajas);
                } else {
                    MessageBox(VentCrearFacturas, L"Error al actualizar archivo de cajas", L"Error", MB_ICONERROR);
                }
                    
                        MessageBox(VentCrearFacturas, L"Factura guardada exitosamente", L"Éxito", MB_OK);
                    
                        // Limpiar los campos de entrada
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_CEDULA_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_NOMBRE_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_APELLIDO_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_DIRECCION_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_TELEFONO_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_CANTIDAD_PRODUCTO_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_CODIGO_PRODUCTO_FACTURA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_BRUTO), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PORCENTAJE_IVA), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_TOTAL), L"");
                        SetWindowText(GetDlgItem(VentCrearFacturas, EDT_CAJA_FACTURA), L"");
                        
                    
                        DestroyWindow(VentCrearFacturas);
                        HWND nVentCrearFacturas = CreateWindowEx(0, L"CL_VentanaCrearFactura", L"CREAR FACTURA", WS_OVERLAPPEDWINDOW, 20, 5, 1080, 720, NULL, NULL, instancia, NULL);
                        ShowWindow(nVentCrearFacturas, SW_SHOW);
                        UpdateWindow(nVentCrearFacturas);
                        break;
                    }
           
                    case BTN_IMPRIMIR_FACTURA:{
                        wchar_t buffer[1024];
                        FILE *archivo_factura = fopen("FacturaImpresion.txt", "w");
                        if (archivo_factura == NULL) {
                            MessageBox(VentCrearFacturas, L"Error al crear el archivo de impresión", L"Error", MB_ICONERROR);
                            break;
                        }

                        // Escribir encabezado de la factura
                        fwprintf(archivo_factura, L"HIPERMERCADO CACHAMAY\n");
                        fwprintf(archivo_factura, L"RIF: J-123456789\n");
                        fwprintf(archivo_factura, L"Teléfono: 0414-0463588\n");
                        fwprintf(archivo_factura, L"----------------------------------------\n");

                        // Escribir datos de la factura
                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_ID_HIPERMERCADO), buffer, 15);
                        fwprintf(archivo_factura, L"ID Hipermercado: %ls\n", buffer);

                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_NUMERO_FACTURA), buffer, 128);
                        fwprintf(archivo_factura, L"Número Factura: %ls\n", buffer);

                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_FECHA_FACTURA), buffer, 20);
                        fwprintf(archivo_factura, L"Fecha: %ls\n", buffer);

                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_CLIENTE_FACTURA), buffer, 150);
                        fwprintf(archivo_factura, L"Cliente: %ls\n", buffer);

                        fwprintf(archivo_factura, L"----------------------------------------\n");

                        // Escribir productos comprados
                        HWND hListViewFactura = FindWindowEx(VentCrearFacturas, NULL, WC_LISTVIEW, L"Compra");
                        if (hListViewFactura == NULL) {
                            MessageBox(VentCrearFacturas, L"ListView de factura no encontrado", L"Error", MB_ICONERROR);
                            fclose(archivo_factura);
                            break;
                        }

                        int itemCount = ListView_GetItemCount(hListViewFactura);
                        for (int i = 0; i < itemCount; i++) {
                            wchar_t itemText[128];
                            ListView_GetItemText(hListViewFactura, i, 0, itemText, 128);
                            fwprintf(archivo_factura, L"Producto: %ls\n", itemText);

                            ListView_GetItemText(hListViewFactura, i, 1, itemText, 128);
                            fwprintf(archivo_factura, L"Cantidad: %ls\n", itemText);

                            ListView_GetItemText(hListViewFactura, i, 2, itemText, 128);
                            fwprintf(archivo_factura, L"Precio Unitario: %ls\n", itemText);

                            fwprintf(archivo_factura, L"----------------------------------------\n");
                        }

                        // Escribir totales de la factura
                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_BRUTO), buffer, 128);
                        fwprintf(archivo_factura, L"Pago Bruto: %ls\n", buffer);

                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_PORCENTAJE_IVA), buffer, 128);
                        fwprintf(archivo_factura, L"Porcentaje IVA: %ls\n", buffer);

                        GetWindowText(GetDlgItem(VentCrearFacturas, EDT_PAGO_TOTAL), buffer, 128);
                        fwprintf(archivo_factura, L"Pago Total: %ls\n", buffer);

                        fclose(archivo_factura);
                        MessageBox(VentCrearFacturas, L"Factura impresa exitosamente en FacturaImpresion.txt", L"Éxito", MB_OK);
                        break;

                        
                    }
           
                    case BTN_CERRAR_FACTURA:{
                        DestroyWindow(VentCrearFacturas);
                    }
                }       
            break;                                  
        }
    
        case WM_CLOSE: {
            DestroyWindow(VentCrearFacturas);
            break;
        }

        default: {
            return DefWindowProc(VentCrearFacturas, msg, wParam, lParam);
        }
        
    }
}

LRESULT CALLBACK VentanaMostrarFactura(HWND VentMostrarFacturas, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HINSTANCE instancia;
    HWND ListViewFactura;

    switch(msg){
               
        case WM_CREATE:{      
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;
          {
            // Botón "ATRAS"
            CreateWindowEx(0, L"BUTTON", L"ATRAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 30, 625, 150, 25, VentMostrarFacturas, (HMENU)BTN_ATRAS4, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"BUSCAR FACTURA", BS_PUSHBUTTON | WS_CHILD | BS_CENTER | WS_VISIBLE, 780, 10, 150, 25,VentMostrarFacturas,(HMENU)BTN_BUSCAR_FACTURA, instancia, NULL);
        

            // ListView para mostrar las facturas
            ListViewFactura = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Facturas", WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING, 25, 350, 950, 250, VentMostrarFacturas, NULL, instancia, NULL);
            ListView_SetExtendedListViewStyle(ListViewFactura, LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);
            FacturasEnListView(ListViewFactura);



            // Controles adicionales
            CreateWindowEx(0, L"STATIC", L"ID Hipermercado:", SS_LEFT | WS_CHILD | WS_VISIBLE, 33, 10, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 183, 10, 200, 25, VentMostrarFacturas, (HMENU)EDT_ID_HIPERMERCADO, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Número Factura:", SS_LEFT | WS_CHILD | WS_VISIBLE, 400, 10, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 550, 10, 200, 25, VentMostrarFacturas, (HMENU)EDT_NUMERO_FACTURA, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Fecha:", SS_LEFT | WS_CHILD | WS_VISIBLE, 33, 40, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 183, 40, 200, 25, VentMostrarFacturas, (HMENU)EDT_FECHA_FACTURA, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Cliente:", SS_LEFT | WS_CHILD | WS_VISIBLE, 400, 40, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 550, 40, 200, 25, VentMostrarFacturas, (HMENU)EDT_CLIENTE_FACTURA, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Pago Bruto:", SS_LEFT | WS_CHILD | WS_VISIBLE, 33, 70, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 183, 70, 200, 25, VentMostrarFacturas, (HMENU)EDT_PAGO_BRUTO, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Porcentaje IVA:", SS_LEFT | WS_CHILD | WS_VISIBLE, 400, 70, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 550, 70, 200, 25, VentMostrarFacturas, (HMENU)EDT_PORCENTAJE_IVA, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Pago Total:", SS_LEFT | WS_CHILD | WS_VISIBLE, 33, 100, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 183, 100, 200, 25, VentMostrarFacturas, (HMENU)EDT_PAGO_TOTAL, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Caja:", SS_LEFT | WS_CHILD | WS_VISIBLE, 400, 100, 150, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 550, 100, 200, 25, VentMostrarFacturas, (HMENU)EDT_CAJA_FACTURA, instancia, NULL);
           }

          {  // ListView para mostrar los productos comprados
            HWND ListViewProductosComprados = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Productos Comprados", WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING, 33, 130, 720, 85, VentMostrarFacturas, NULL, instancia, NULL);
            ListView_SetExtendedListViewStyle(ListViewProductosComprados, LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);

            // Agregar columnas al ListView de productos comprados
            LVCOLUMN colProd = {0};
            colProd.mask = LVCF_TEXT | LVCF_WIDTH;

            // Primera columna: "Producto"
            colProd.pszText = L"Producto";
            colProd.cx = 300; // ancho en píxeles
            ListView_InsertColumn(ListViewProductosComprados, 0, &colProd);

            // Segunda columna: "Cantidad"
            colProd.pszText = L"Cantidad";
            colProd.cx = 100;
            ListView_InsertColumn(ListViewProductosComprados, 1, &colProd);

            // Tercera columna: "Precio Unitario"
            colProd.pszText = L"Precio Unitario";
            colProd.cx = 150;
            ListView_InsertColumn(ListViewProductosComprados, 2, &colProd);
          }

          { //Elementos del cliente
            CreateWindowEx(0, L"BUTTON", L"Datos del Cliente", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 33, 215, 720, 120, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"STATIC", L"Cédula:", SS_LEFT | WS_CHILD | WS_VISIBLE, 40, 240, 100, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 150, 240, 200, 25, VentMostrarFacturas, (HMENU)EDT_CEDULA_CLIENTE, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Nombre:", SS_LEFT | WS_CHILD | WS_VISIBLE, 370, 240, 100, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 480, 240, 200, 25, VentMostrarFacturas, (HMENU)EDT_NOMBRE_CLIENTE, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Apellido:", SS_LEFT | WS_CHILD | WS_VISIBLE, 40, 270, 100, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 150, 270, 200, 25, VentMostrarFacturas, (HMENU)EDT_APELLIDO_CLIENTE, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Dirección:", SS_LEFT | WS_CHILD | WS_VISIBLE, 370, 270, 100, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 480, 270, 200, 25, VentMostrarFacturas, (HMENU)EDT_DIRECCION_CLIENTE, instancia, NULL);

            CreateWindowEx(0, L"STATIC", L"Teléfono:", SS_LEFT | WS_CHILD | WS_VISIBLE, 40, 300, 100, 25, VentMostrarFacturas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_READONLY | ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 150, 300, 200, 25, VentMostrarFacturas, (HMENU)EDT_TELEFONO_CLIENTE, instancia, NULL);
           }
             
           break;
            }


        case WM_COMMAND:{
            switch(LOWORD(wParam)){
                case BTN_BUSCAR_FACTURA: {
                    wchar_t buffer[128];
                    // Obtener el número de factura ingresado en el control correspondiente
                    GetWindowText(GetDlgItem(VentMostrarFacturas, EDT_NUMERO_FACTURA), buffer, 128);
                    int numFactura = _wtoi(buffer);
                
                    // Buscar la factura en el arreglo global
                    int indice = -1;
                    for (int i = 0; i < cant_facturas; i++) {
                        if (d_facturas[i].numero_factura == numFactura) {
                            indice = i;
                            break;
                        }
                    }
                
                    if (indice == -1) {
                        MessageBox(VentMostrarFacturas, L"Factura no encontrada", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }
                
                    // Actualizar los controles de la ventana con los datos de la factura encontrada
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_ID_HIPERMERCADO), d_facturas[indice].ID_hipermercado);
                
                    swprintf_s(buffer, 128, L"%d", d_facturas[indice].numero_factura);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_NUMERO_FACTURA), buffer);
                
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_FECHA_FACTURA), d_facturas[indice].fecha);
                
                    // Mostrar datos del cliente (nombre completo en un control)
                    wchar_t clienteCompleto[300];
                    swprintf_s(clienteCompleto, 300, L"%ls %ls", d_facturas[indice].cliente.nombre, d_facturas[indice].cliente.apellido);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_CLIENTE_FACTURA), clienteCompleto);
                
                    // Actualizar montos de la factura
                    swprintf_s(buffer, 128, L"%.2f", d_facturas[indice].pago_bruto);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_PAGO_BRUTO), buffer);
                
                    swprintf_s(buffer, 128, L"%.2f", d_facturas[indice].porcentajeIVA);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_PORCENTAJE_IVA), buffer);
                
                    swprintf_s(buffer, 128, L"%.2f", d_facturas[indice].pago_total);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_PAGO_TOTAL), buffer);
                
                    swprintf_s(buffer, 128, L"%d", d_facturas[indice].caja.numero_caja);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_CAJA_FACTURA), buffer);
                
                    // Actualizar los detalles del cliente en el groupbox
                    swprintf_s(buffer, 128, L"%d", d_facturas[indice].cliente.cedula);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_CEDULA_CLIENTE), buffer);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_NOMBRE_CLIENTE), d_facturas[indice].cliente.nombre);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_APELLIDO_CLIENTE), d_facturas[indice].cliente.apellido);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_DIRECCION_CLIENTE), d_facturas[indice].cliente.direccion);
                    swprintf_s(buffer, 128, L"%d", d_facturas[indice].cliente.telefono);
                    SetWindowText(GetDlgItem(VentMostrarFacturas, EDT_TELEFONO_CLIENTE), buffer);
                
                    // Actualizar el ListView de "Productos Comprados"
                    HWND hListViewProductosComprados = FindWindowEx(VentMostrarFacturas, NULL, WC_LISTVIEW, L"Productos Comprados");
                    if (hListViewProductosComprados) {
                        ListView_DeleteAllItems(hListViewProductosComprados);
                
                        // Copiar la cadena de productos a un buffer local
                        wchar_t productosCopia[500];
                        wcscpy_s(productosCopia, 500, d_facturas[indice].productos_comprados);
                
                        // Tokenizar la cadena usando la coma como separador.
                        // Se espera que cada token tenga el formato "Producto x Cantidad"
                        wchar_t *context;
                        wchar_t *token = wcstok_s(productosCopia, L",", &context);
                        int itemIndex = 0;
                        while (token != NULL) {
                            // Eliminar espacios iniciales
                            while (*token == L' ')
                                token++;
                
                            // Buscar el separador " x " para dividir nombre y cantidad
                            wchar_t *sep = wcsstr(token, L" x ");
                            if (sep) {
                                *sep = L'\0'; // Finaliza la cadena del nombre
                                sep += 3;     // Apunta a la cantidad
                                wchar_t *nombreProducto = token;
                                wchar_t *cantidadStr = sep;
                
                                LVITEM lvItem = {0};
                                lvItem.mask = LVIF_TEXT;
                                lvItem.iItem = itemIndex;
                                lvItem.pszText = nombreProducto;
                                int index = ListView_InsertItem(hListViewProductosComprados, &lvItem);
                
                                // Columna 1: Cantidad
                                ListView_SetItemText(hListViewProductosComprados, index, 1, cantidadStr);
                                // Columna 2: Precio Unitario (no se almacena, se muestra "N/A")
                                ListView_SetItemText(hListViewProductosComprados, index, 2, L"N/A");
                
                                itemIndex++;
                            }
                            token = wcstok_s(NULL, L",", &context);
                        }
                    }
                
                    break;
                }


                case BTN_ATRAS4:{

                    DestroyWindow(VentMostrarFacturas);

                    break;
                }

            }


            break;
        }

        case WM_CLOSE:{
            DestroyWindow(VentMostrarFacturas);
            break;
        }
        
       default:{return DefWindowProc(VentMostrarFacturas, msg, wParam, lParam);} 
    }
                 

}

LRESULT CALLBACK VentanaVentas(HWND VentVentas, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HINSTANCE instancia;

    HWND ListViewVentas;



    switch (msg) {

        case WM_CREATE:{
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;
            // Grupo: Ventas Diarias
            CreateWindowEx(0, L"BUTTON", L"Ventas Diarias", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 20, 20, 400, 200, VentVentas, NULL, instancia, NULL);
            
            // Ventas Diarias
            CreateWindowEx(0, L"STATIC", L"Ventas Diarias:", SS_LEFT | WS_CHILD | WS_VISIBLE, 40, 60, 150, 25, VentVentas, NULL, instancia, NULL);
            CreateWindowEx(0, DATETIMEPICK_CLASS, L"", WS_BORDER | WS_CHILD | WS_VISIBLE | DTS_SHORTDATEFORMAT, 200, 60, 200, 25, VentVentas, (HMENU)EDT_VENTAS_DIARIAS, instancia, NULL);
           
            CreateWindowEx(0, L"BUTTON", L"BUSCAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 150, 100, 120, 25, VentVentas, (HMENU)BTN_BUSCAR1, instancia, NULL);
            

            // Grupo: Ventas Mensuales
            CreateWindowEx(0, L"BUTTON", L"Ventas Mensuales(MM/AA)", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 20, 240, 400, 200, VentVentas, NULL, instancia, NULL);
            
            // Ventas Mensuales
            CreateWindowEx(0, L"STATIC", L"Ventas Mensuales:", SS_LEFT | WS_CHILD | WS_VISIBLE, 40, 280, 150, 25, VentVentas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"",  ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 200, 280, 200, 25, VentVentas, (HMENU)EDT_VENTAS_MENSUEALES, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"BUSCAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 150, 320, 120, 25, VentVentas, (HMENU)BTN_BUSCAR2, instancia, NULL);
            

            // Botón "ATRAS"
            CreateWindowEx(0, L"BUTTON", L"ATRAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 150, 500, 150, 30, VentVentas, (HMENU)BTN_ATRAS8, instancia, NULL);
            

            ListViewVentas = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Ventas",
                WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING,
                450, 20, 500, 420, VentVentas, NULL, instancia, NULL);
            ListView_SetExtendedListViewStyle(ListViewVentas,
                LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);
            
            // Agregar columnas al ListView de ventas
            LVCOLUMN col = {0};
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            
            // Columna 0: "Fecha"
            col.pszText = L"Fecha";
            col.cx = 150;
            ListView_InsertColumn(ListViewVentas, 0, &col);
            
            // Columna 1: "Número de Factura"
            col.pszText = L"Número de Factura";
            col.cx = 150;
            ListView_InsertColumn(ListViewVentas, 1, &col);
            
            // Columna 2: "Cliente"
            col.pszText = L"Cliente";
            col.cx = 200;
            ListView_InsertColumn(ListViewVentas, 2, &col);
            
            // Columna 3: "Pago Bruto $"
            col.pszText = L"Pago Bruto $";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 3, &col);
            
            // Columna 4: "Pago Bruto Bs"
            col.pszText = L"Pago Bruto Bs";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 4, &col);
            
            // Columna 5: "Pago Bruto EUR"
            col.pszText = L"Pago Bruto EUR";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 5, &col);
            
            // Columna 6: "Pago Bruto PES"
            col.pszText = L"Pago Bruto PES";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 6, &col);
            
            // Columna 7: "Porcentaje IVA"
            col.pszText = L"Porcentaje IVA";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 7, &col);
            
            // Columna 8: "Pago Total $"
            col.pszText = L"Pago Total $";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 8, &col);
            
            // Columna 9: "Pago Total Bs"
            col.pszText = L"Pago Total Bs";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 9, &col);
            
            // Columna 10: "Pago Total EUR"
            col.pszText = L"Pago Total EUR";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 10, &col);
            
            // Columna 11: "Pago Total PES"
            col.pszText = L"Pago Total PES";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 11, &col);
            
            // Columna 12: "Caja"
            col.pszText = L"Caja";
            col.cx = 50;
            ListView_InsertColumn(ListViewVentas, 12, &col);
            
            // Columna 13: "Método de pago"
            col.pszText = L"Método de pago";
            col.cx = 100;
            ListView_InsertColumn(ListViewVentas, 13, &col);
            
            
            break;
        }

        case WM_COMMAND:{
            
            
        
            switch(LOWORD(wParam)){
                case BTN_BUSCAR1: {
                    SYSTEMTIME st;
                    // Obtener la fecha seleccionada en el DateTimePicker
                    SendDlgItemMessage(VentVentas, EDT_VENTAS_DIARIAS, DTM_GETSYSTEMTIME, 0, (LPARAM)&st);
                    wchar_t queryDate[20];
                    swprintf_s(queryDate, 20, L"%02d/%02d/%04d", st.wDay, st.wMonth, st.wYear);
                
                    // Obtener el handle del ListView "Ventas"
                    HWND hListView = FindWindowEx(VentVentas, NULL, WC_LISTVIEW, NULL);
                    if (hListView == NULL) {
                        MessageBox(VentVentas, L"ListView de ventas no encontrado", L"Error", MB_OK | MB_ICONERROR);
                        break;
                    }
                
                    // Limpiar elementos previos
                    ListView_DeleteAllItems(hListView);
                
                    int found = 0;
                    for (int i = 0; i < cant_facturas; i++) {
                        // Comparar la fecha de la factura con la fecha consultada
                        if (wcscmp(d_facturas[i].fecha, queryDate) == 0) {
                            LVITEM lvItem = {0};
                            wchar_t buffer[128];
                            lvItem.mask = LVIF_TEXT;
                            lvItem.iItem = ListView_GetItemCount(hListView);
                
                            // Columna 0: Fecha
                            swprintf_s(buffer, 128, L"%ls", d_facturas[i].fecha);
                            lvItem.pszText = buffer;
                            int index = ListView_InsertItem(hListView, &lvItem);
                
                            // Columna 1: Número de Factura
                            swprintf_s(buffer, 128, L"%d", d_facturas[i].numero_factura);
                            ListView_SetItemText(hListView, index, 1, buffer);
                
                            // Columna 2: Cliente
                            ListView_SetItemText(hListView, index, 2, d_facturas[i].cliente.nombre);
                
                            // Determinar el método de pago
                            wchar_t *metodo = d_facturas[i].metodo_pago; // Por ejemplo "Bs", "$", "EUR" o "PES"
                
                            // --- Pago Bruto ---
                            // Columna 3: Pago Bruto ($)
                            // Columna 4: Pago Bruto (Bs)
                            // Columna 5: Pago Bruto (EUR)
                            // Columna 6: Pago Bruto (PES)
                            if (wcscmp(metodo, L"Bs") == 0) {
                                ListView_SetItemText(hListView, index, 3, L"N/P");
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_bruto);
                                ListView_SetItemText(hListView, index, 4, buffer);
                                ListView_SetItemText(hListView, index, 5, L"N/P");
                                ListView_SetItemText(hListView, index, 6, L"N/P");
                            } else if (wcscmp(metodo, L"$") == 0) {
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_bruto);
                                ListView_SetItemText(hListView, index, 3, buffer);
                                ListView_SetItemText(hListView, index, 4, L"N/P");
                                ListView_SetItemText(hListView, index, 5, L"N/P");
                                ListView_SetItemText(hListView, index, 6, L"N/P");
                            } else if (wcscmp(metodo, L"EUR") == 0) {
                                ListView_SetItemText(hListView, index, 3, L"N/P");
                                ListView_SetItemText(hListView, index, 4, L"N/P");
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_bruto);
                                ListView_SetItemText(hListView, index, 5, buffer);
                                ListView_SetItemText(hListView, index, 6, L"N/P");
                            } else if (wcscmp(metodo, L"PES") == 0) {
                                ListView_SetItemText(hListView, index, 3, L"N/P");
                                ListView_SetItemText(hListView, index, 4, L"N/P");
                                ListView_SetItemText(hListView, index, 5, L"N/P");
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_bruto);
                                ListView_SetItemText(hListView, index, 6, buffer);
                            } else {
                                // Si no se reconoce el método, se ponen N/P en todas las columnas de Pago Bruto
                                ListView_SetItemText(hListView, index, 3, L"N/P");
                                ListView_SetItemText(hListView, index, 4, L"N/P");
                                ListView_SetItemText(hListView, index, 5, L"N/P");
                                ListView_SetItemText(hListView, index, 6, L"N/P");
                            }
                
                            // Columna 7: Porcentaje IVA (siempre se muestra)
                            swprintf_s(buffer, 128, L"%.2f", d_facturas[i].porcentajeIVA);
                            ListView_SetItemText(hListView, index, 7, buffer);
                
                            // --- Pago Total ---
                            // Columna 8: Pago Total ($)
                            // Columna 9: Pago Total (Bs)
                            // Columna 10: Pago Total (EUR)
                            // Columna 11: Pago Total (PES)
                            if (wcscmp(metodo, L"Bs") == 0) {
                                ListView_SetItemText(hListView, index, 8, L"N/P");
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_total);
                                ListView_SetItemText(hListView, index, 9, buffer);
                                ListView_SetItemText(hListView, index, 10, L"N/P");
                                ListView_SetItemText(hListView, index, 11, L"N/P");
                            } else if (wcscmp(metodo, L"$") == 0) {
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_total);
                                ListView_SetItemText(hListView, index, 8, buffer);
                                ListView_SetItemText(hListView, index, 9, L"N/P");
                                ListView_SetItemText(hListView, index, 10, L"N/P");
                                ListView_SetItemText(hListView, index, 11, L"N/P");
                            } else if (wcscmp(metodo, L"EUR") == 0) {
                                ListView_SetItemText(hListView, index, 8, L"N/P");
                                ListView_SetItemText(hListView, index, 9, L"N/P");
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_total);
                                ListView_SetItemText(hListView, index, 10, buffer);
                                ListView_SetItemText(hListView, index, 11, L"N/P");
                            } else if (wcscmp(metodo, L"PES") == 0) {
                                ListView_SetItemText(hListView, index, 8, L"N/P");
                                ListView_SetItemText(hListView, index, 9, L"N/P");
                                ListView_SetItemText(hListView, index, 10, L"N/P");
                                swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_total);
                                ListView_SetItemText(hListView, index, 11, buffer);
                            } else {
                                ListView_SetItemText(hListView, index, 8, L"N/P");
                                ListView_SetItemText(hListView, index, 9, L"N/P");
                                ListView_SetItemText(hListView, index, 10, L"N/P");
                                ListView_SetItemText(hListView, index, 11, L"N/P");
                            }
                
                            // Columna 12: Caja
                            swprintf_s(buffer, 128, L"%d", d_facturas[i].caja.numero_caja);
                            ListView_SetItemText(hListView, index, 12, buffer);
                
                            // Columna 13: Método de pago
                            ListView_SetItemText(hListView, index, 13, d_facturas[i].metodo_pago);
                
                            found = 1;
                        }
                    }
                    if (!found) {
                        MessageBox(VentVentas, L"No se encontraron ventas en la fecha seleccionada", L"Información", MB_OK | MB_ICONINFORMATION);
                    }
                
                    // Mostrar total del día (suma de los totales sin distinción de moneda)
                    float totalVentas = 0.0f;
                    for (int i = 0; i < cant_facturas; i++) {
                        if (wcscmp(d_facturas[i].fecha, queryDate) == 0) {
                            totalVentas += d_facturas[i].pago_total;
                        }
                    }
                    wchar_t totalStr[100];
                    swprintf_s(totalStr, 100, L"Total del día: %.2f", totalVentas);
                    CreateWindowEx(0, L"STATIC", totalStr, WS_CHILD | WS_VISIBLE | SS_CENTER, 40, 140, 300, 25, VentVentas, NULL, instancia, NULL);
                
                    break;
                }
           
                case BTN_BUSCAR2: {
                            wchar_t texto[100];
                            GetDlgItemText(VentVentas, EDT_VENTAS_MENSUEALES, texto, 100);
                            // Verifica que el formato sea exactamente "MM/AA"
                            if (wcslen(texto) != 5 || texto[2] != L'/') {
                                MessageBox(VentVentas, L"Formato de fecha incorrecto. Use MM/AA", L"Error", MB_ICONERROR | MB_OK);
                                break;
                            }
                            int mes, anio_input;
                            if (swscanf_s(texto, L"%2d/%2d", &mes, &anio_input) != 2) {
                                MessageBox(VentVentas, L"Formato de fecha incorrecto. Use MM/AA", L"Error", MB_ICONERROR | MB_OK);
                                break;
                            }
                            if (mes < 1 || mes > 12) {
                                MessageBox(VentVentas, L"Mes inválido. Debe estar entre 01 y 12", L"Error", MB_ICONERROR | MB_OK);
                                break;
                            }

                            // Buscamos las ventas mensuales
                            HWND hListView = FindWindowEx(VentVentas, NULL, WC_LISTVIEW, L"Ventas");
                            if (hListView == NULL) {
                                MessageBox(VentVentas, L"ListView de ventas no encontrado", L"Error", MB_ICONERROR | MB_OK);
                                break;
                            }
                            ListView_DeleteAllItems(hListView);

                            int found = 0;
                            // Recorrer cada factura y comparar mes y año (tomando los dos últimos dígitos del año)
                            for (int i = 0; i < cant_facturas; i++) {
                                int dia, mesFactura, anio;
                                if (swscanf_s(d_facturas[i].fecha, L"%d/%d/%d", &dia, &mesFactura, &anio) != 3)
                                    continue;
                                if (mesFactura == mes && (anio % 100) == anio_input) {
                                    LVITEM lvItem = {0};
                                    wchar_t buffer[128];
                                    lvItem.mask = LVIF_TEXT;
                                    lvItem.iItem = ListView_GetItemCount(hListView);

                                    // Columna 0: Fecha
                                    swprintf_s(buffer, 128, L"%ls", d_facturas[i].fecha);
                                    lvItem.pszText = buffer;
                                    int index = ListView_InsertItem(hListView, &lvItem);

                                    // Columna 1: Número de Factura
                                    swprintf_s(buffer, 128, L"%d", d_facturas[i].numero_factura);
                                    ListView_SetItemText(hListView, index, 1, buffer);

                                    // Columna 2: Cliente (nombre)
                                    ListView_SetItemText(hListView, index, 2, d_facturas[i].cliente.nombre);

                                    // Columna 3: Pago Bruto
                                    swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_bruto);
                                    ListView_SetItemText(hListView, index, 3, buffer);

                                    // Columna 4: Porcentaje IVA
                                    swprintf_s(buffer, 128, L"%.2f", d_facturas[i].porcentajeIVA);
                                    ListView_SetItemText(hListView, index, 4, buffer);

                                    // Columna 5: Pago Total
                                    swprintf_s(buffer, 128, L"%.2f", d_facturas[i].pago_total);
                                    ListView_SetItemText(hListView, index, 5, buffer);

                                    // Columna 6: Caja (número)
                                    swprintf_s(buffer, 128, L"%d", d_facturas[i].caja.numero_caja);
                                    ListView_SetItemText(hListView, index, 6, buffer);

                                    found = 1;
                                }
                            }
                            if (!found) {
                                MessageBox(VentVentas, L"No se encontraron ventas para el mes indicado.", L"Información", MB_ICONINFORMATION | MB_OK);
                            }


                            float totalVentas = 0.0f;
                            for (int i = 0; i < cant_facturas; i++) {
                                int dia, mesFactura, anio;
                                if (swscanf_s(d_facturas[i].fecha, L"%d/%d/%d", &dia, &mesFactura, &anio) == 3) {
                                    if (mesFactura == mes && (anio % 100) == anio_input) {
                                        totalVentas += d_facturas[i].pago_total;
                                    }
                                }
                            }
                            wchar_t totalStr[100];
                            swprintf_s(totalStr, 100, L"Total del mes $: %.2f", totalVentas);
                            CreateWindowEx(0, L"STATIC", totalStr, WS_CHILD | WS_VISIBLE | SS_CENTER, 40, 390, 300, 25, VentVentas, NULL, instancia, NULL);



                            break;
                        }
          
                case BTN_ATRAS8:{
                    DestroyWindow(VentVentas);
                }
          
                    }
      
      
        break;
    }



        case WM_CLOSE: {
            DestroyWindow(VentVentas);
            break;
        }

        default: {
            return DefWindowProc(VentVentas, msg, wParam, lParam);
        }
    }

    return 0;
}

LRESULT CALLBACK VentanaCajas(HWND VentCajas, UINT msg, WPARAM wParam, LPARAM lParam) {
 
    static HINSTANCE instancia;
    HWND ListViewCaja;
  
    
    switch (msg) {
        case WM_CREATE: {
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;

            {
            CreateWindowEx(0, L"BUTTON", L"Datos de Caja", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 10, 10, 450, 300, VentCajas, NULL, instancia, NULL);
            
            // Número de Caja
            CreateWindowEx(0, L"STATIC", L"NÚMERO CAJA", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 40, 100, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 130, 40, 150, 25, VentCajas, (HMENU)EDT_NUMERO_CAJA, instancia, NULL);
            
            CreateWindowEx(0, L"BUTTON", L"BUSCAR CAJA", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 300, 40, 120, 25, VentCajas, (HMENU)BTN_BUSCAR_CAJA, instancia, NULL);


            // Monto en Bolívares
            CreateWindowEx(0, L"STATIC", L"MONTO BS", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 90, 100, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER | ES_READONLY, 130, 90, 150, 25, VentCajas, (HMENU)EDT_BS_CAJA, instancia, NULL);
            
            // Monto en Dólares
            CreateWindowEx(0, L"STATIC", L"MONTO $", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 140, 100, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER | ES_READONLY, 130, 140, 150, 25, VentCajas, (HMENU)EDT_DOL_CAJA, instancia, NULL);
            
            // Monto en Euros
            CreateWindowEx(0, L"STATIC", L"MONTO EUR", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 190, 100, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER | ES_READONLY, 130, 190, 150, 25, VentCajas, (HMENU)EDT_EUR_CAJA, instancia, NULL);
            
            // Monto en Pesos
            CreateWindowEx(0, L"STATIC", L"MONTO PES", SS_CENTER | WS_CHILD | WS_VISIBLE, 20, 240, 100, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER | ES_READONLY, 130, 240, 150, 25, VentCajas, (HMENU)EDT_PES_CAJA, instancia, NULL);
            
            
            CreateWindowEx(0, L"BUTTON", L"Datos Encargado", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 480, 10, 430, 300, VentCajas, NULL, instancia, NULL);
            
            // Cédula del Encargado
            CreateWindowEx(0, L"STATIC", L"CÉDULA", SS_CENTER | WS_CHILD | WS_VISIBLE, 500, 40, 150, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER, 660, 40, 150, 25, VentCajas, (HMENU)EDT_CEDULA_ENCARGADO, instancia, NULL);
            
            // Nombre del Encargado
            CreateWindowEx(0, L"STATIC", L"NOMBRE", SS_CENTER | WS_CHILD | WS_VISIBLE, 500, 90, 150, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY, 660, 90, 150, 25, VentCajas, (HMENU)EDT_NOMBRE_ENCARGADO, instancia, NULL);
            
            // Apellido del Encargado
            CreateWindowEx(0, L"STATIC", L"APELLIDO", SS_CENTER | WS_CHILD | WS_VISIBLE, 500, 140, 150, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY, 660, 140, 150, 25, VentCajas, (HMENU)EDT_APELLIDO_ENCARGADO, instancia, NULL);
            
            // Dirección del Encargado
            CreateWindowEx(0, L"STATIC", L"DIRECCIÓN", SS_CENTER | WS_CHILD | WS_VISIBLE, 500, 190, 150, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY, 660, 190, 150, 25, VentCajas, (HMENU)EDT_DIRECCION_ENCARGADO, instancia, NULL);
            
            // Teléfono del Encargado
            CreateWindowEx(0, L"STATIC", L"TELEFONO", SS_CENTER | WS_CHILD | WS_VISIBLE, 500, 240, 150, 25, VentCajas, NULL, instancia, NULL);
            CreateWindowEx(0, L"EDIT", L"", ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY, 660, 240, 150, 25, VentCajas, (HMENU)EDT_TELEFONO_ENCARGADO, instancia, NULL);
            
            //Boton para buscar el encargado
            CreateWindowEx(0, L"BUTTON", L"BUSCAR", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 815, 40, 90,25, VentCajas, (HMENU)BTN_BUSCAR_CEDULA_ENCARGADO, instancia, NULL);
        
            // ListView para mostrar las cajas
            
            ListViewCaja = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"Cajas", WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_SORTASCENDING, 10, 320, 900, 250, VentCajas, NULL, instancia, NULL);
            ListView_SetExtendedListViewStyle(ListViewCaja, LVS_EX_GRIDLINES | LVS_EX_JUSTIFYCOLUMNS | LVS_EX_FULLROWSELECT | LVS_EX_HEADERINALLVIEWS);
            CajasEnListView(ListViewCaja);
            
    
            // Botones parte inferior
            
            CreateWindowEx(0, L"BUTTON", L"ATRAS", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 250, 580, 150, 30, VentCajas, (HMENU)BTN_ATRAS8, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"GUARDAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 420, 580, 150, 30, VentCajas, (HMENU)BTN_GUARDAR_CAJA, instancia, NULL);
            CreateWindowEx(0, L"BUTTON", L"LIMPIAR", BS_PUSHBUTTON | BS_CENTER | WS_CHILD | WS_VISIBLE, 590, 580, 150, 30, VentCajas, (HMENU)BTN_LIMPIAR_CAJA, instancia, NULL);
            
            }
                  
                break;
            }
            
        case WM_COMMAND:{
            switch (LOWORD(wParam)) {

                case BTN_BUSCAR_CAJA:{
                    if (GetWindowTextLength(GetDlgItem(VentCajas, EDT_NUMERO_CAJA)) == 0) {
                        MessageBox(VentCajas, L"Debe introducir un número de caja a buscar", L"ERROR", MB_ICONERROR | MB_OK);
                        break;
                    }

                    wchar_t buffer[10];
                    GetDlgItemText(VentCajas, EDT_NUMERO_CAJA, buffer, 10);
                    int numero_caja = _wtoi(buffer);

                    

                    int caja_encontrada = 0;
                    for(int i = 0; i < cant_cajas; i++){ 
                    if(numero_caja == d_cajas[i].numero_caja){
                        wchar_t buffer[50]; // Buffer para almacenar el número convertido a texto

                        // Convertir y mostrar los valores float en los campos correspondientes
                        swprintf_s(buffer, 50, L"%.2f", d_cajas[i].bolivares_facturados);
                        SetWindowText(GetDlgItem(VentCajas, EDT_BS_CAJA), buffer);
                        
                        swprintf_s(buffer, 50, L"%.2f", d_cajas[i].dolares_facturados);
                        SetWindowText(GetDlgItem(VentCajas, EDT_DOL_CAJA), buffer);
                        
                        swprintf_s(buffer, 50, L"%.2f", d_cajas[i].euros_facturados);
                        SetWindowText(GetDlgItem(VentCajas, EDT_EUR_CAJA), buffer);
                        
                        swprintf_s(buffer, 50, L"%.2f", d_cajas[i].pesos_facturados);
                        SetWindowText(GetDlgItem(VentCajas, EDT_PES_CAJA), buffer);
 
                        swprintf_s(buffer, 100, L"%d", d_cajas[i].encargador.cedula_trabajador);
                        SetWindowText(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO), buffer);
                        SetWindowText(GetDlgItem(VentCajas, EDT_NOMBRE_ENCARGADO), d_cajas[i].encargador.nombre);
                        SetWindowText(GetDlgItem(VentCajas, EDT_APELLIDO_ENCARGADO), d_cajas[i].encargador.apellido);
                        SetWindowText(GetDlgItem(VentCajas, EDT_DIRECCION_ENCARGADO), d_cajas[i].encargador.direccion);
                        swprintf_s(buffer, 100, L"%d", d_cajas[i].encargador.telefono);
                        SetWindowText(GetDlgItem(VentCajas, EDT_TELEFONO_ENCARGADO), buffer);

                        caja_encontrada = 1;
                        break;
                    }
 
                    }

                    if (!caja_encontrada) {
                        MessageBox(VentCajas, L"Caja No Encontrada", L"Error", MB_OK | MB_ICONERROR);
                        break;
                
                        }

                        HWND hGuardarButton = GetDlgItem(VentCajas, BTN_LIMPIAR_CAJA);
                        if(hGuardarButton){
                            DestroyWindow(hGuardarButton);
                        }

                    CreateWindowEx(0, L"BUTTON", L"EDITAR", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 420, 580, 150, 30, VentCajas, (HMENU)BTN_EDITAR_CAJA, instancia, NULL);
                    
                    HWND hEliminarButton = GetDlgItem(VentCajas, BTN_GUARDAR_CAJA);
                    if(hGuardarButton){
                        DestroyWindow(hEliminarButton);
                    }

                    CreateWindowEx(0, L"BUTTON", L"ELIMINAR", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 590, 580, 150, 30, VentCajas, (HMENU)BTN_ELIMINAR_CAJA, instancia, NULL);

                    break;
                }

                case BTN_BUSCAR_CEDULA_ENCARGADO:{
                     if(GetWindowTextLength(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO)) == 0){
                        MessageBox(VentCajas, L"Debe llenar el campo cedula para buscar", L"Error", MB_ICONERROR | MB_OK);
                        break;
                     }

                    wchar_t buffer[100];
                    GetWindowText(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO), buffer, 100);
                    int cedula = _wtoi(buffer);

                    int EncargadoEncontrado = 0;

                    for(int i = 0; i < cant_empleados; i++){
                        if(cedula == d_empleados[i].cedula_trabajador){
                            SetWindowText(GetDlgItem(VentCajas, EDT_NOMBRE_ENCARGADO), d_empleados[i].nombre);
                            SetWindowText(GetDlgItem(VentCajas, EDT_APELLIDO_ENCARGADO), d_empleados[i].apellido);
                            SetWindowText(GetDlgItem(VentCajas, EDT_DIRECCION_ENCARGADO), d_empleados[i].direccion);
                            swprintf_s(buffer, 100, L"%d", d_empleados[i].telefono);
                            SetWindowText(GetDlgItem(VentCajas, EDT_TELEFONO_ENCARGADO), buffer);
                            EncargadoEncontrado = 1;
                            break;
                            }
                            }

                            if (!EncargadoEncontrado) {
                            MessageBox(VentCajas, L"Encargado no encontrado.", L"Error", MB_OK | MB_ICONERROR);
                            }
                            break;
                        }
                    
                case BTN_ATRAS8: {
                    DestroyWindow(VentCajas);
                    break;
                }

                case BTN_GUARDAR_CAJA: {
                    if(GetWindowTextLength(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO)) == 0 || GetWindowTextLength (GetDlgItem(VentCajas, EDT_NUMERO_CAJA)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentCajas, EDT_NOMBRE_ENCARGADO)) == 0 || GetWindowTextLength(GetDlgItem(VentCajas, EDT_APELLIDO_ENCARGADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentCajas, EDT_DIRECCION_ENCARGADO)) == 0 || GetWindowTextLength(GetDlgItem(VentCajas, EDT_TELEFONO_ENCARGADO)) == 0){
                        MessageBox(VentCajas, L"Hay campos incompletos", L"Error", MB_ICONERROR | MB_OK);
                        break;
                     }

                    wchar_t buffer[200];
                    GetDlgItemText(VentCajas, EDT_NUMERO_CAJA, buffer, 200);
                    int numero_caja = _wtoi(buffer);

                   if(VerificarCaja(numero_caja, VentCajas)){
                    break;
                   }


                    GetDlgItemText(VentCajas, EDT_NUMERO_CAJA, buffer, 200);
                    d_cajas[cant_cajas].numero_caja = _wtoi(buffer);

                    GetDlgItemText(VentCajas, EDT_CEDULA_ENCARGADO, buffer, 200);
                    d_cajas[cant_cajas].encargador.cedula_trabajador = _wtoi(buffer);

                    GetDlgItemText(VentCajas, EDT_NOMBRE_ENCARGADO, buffer, 200);
                    wcscpy_s(d_cajas[cant_cajas].encargador.nombre, 50, buffer);

                    GetDlgItemText(VentCajas, EDT_APELLIDO_ENCARGADO, buffer, 200);
                    wcscpy_s(d_cajas[cant_cajas].encargador.apellido, 50, buffer);

                    GetDlgItemText(VentCajas, EDT_DIRECCION_ENCARGADO, buffer, 200);
                    wcscpy_s(d_cajas[cant_cajas].encargador.direccion, 100, buffer);

                    GetDlgItemText(VentCajas, EDT_TELEFONO_ENCARGADO, buffer, 200);
                    d_cajas[cant_cajas].encargador.telefono = _wtoi(buffer);

                    FILE *archivo_cajas;
                    archivo_cajas = fopen("cajas.dat", "a");
                    if (archivo_cajas == NULL) {
                        MessageBox(VentCajas, L"ERROR", L"ERROR AL CREAR EL ARCHIVO", MB_OKCANCEL);
                        break;
                    }

                    fprintf(archivo_cajas, "Numero Caja: %d\n", d_cajas[cant_cajas].numero_caja);
                    fprintf(archivo_cajas, "Bolivares Facturados: %.2f\n", d_cajas[cant_cajas].bolivares_facturados);
                    fprintf(archivo_cajas, "Dolares Facturados: %.2f\n", d_cajas[cant_cajas].dolares_facturados);
                    fprintf(archivo_cajas, "Euros Facturados: %.2f\n", d_cajas[cant_cajas].euros_facturados);
                    fprintf(archivo_cajas, "Pesos Facturados: %.2f\n", d_cajas[cant_cajas].pesos_facturados);
                    fprintf(archivo_cajas, "Cedula Encargado: %d\n", d_cajas[cant_cajas].encargador.cedula_trabajador);
                    fprintf(archivo_cajas, "Nombre Encargado: %ls\n", d_cajas[cant_cajas].encargador.nombre);
                    fprintf(archivo_cajas, "Apellido Encargado: %ls\n", d_cajas[cant_cajas].encargador.apellido);
                    fprintf(archivo_cajas, "Direccion Encargado: %ls\n", d_cajas[cant_cajas].encargador.direccion);
                    fprintf(archivo_cajas, "Telefono Encargado: %d\n", d_cajas[cant_cajas].encargador.telefono);
                    fprintf(archivo_cajas, "---------------------\n");

                    fclose(archivo_cajas);

                    cant_cajas++;
                    MessageBox(VentCajas, L"Datos de la caja guardados exitosamente", L"Éxito", MB_OK);
                    SetWindowText(GetDlgItem(VentCajas, EDT_NUMERO_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_BS_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_DOL_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_EUR_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_PES_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_NOMBRE_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_APELLIDO_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_DIRECCION_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_TELEFONO_ENCARGADO), L"");

                    DestroyWindow(VentCajas);
                    HWND VentCajasNueva = CreateWindowEx(0, L"CL_VentanaCajas", L"Cajas", WS_OVERLAPPEDWINDOW, 15, 15, 950, 700, NULL, NULL, instancia, NULL);
                    ShowWindow(VentCajasNueva, SW_SHOW);
                    UpdateWindow(VentCajasNueva);
                    
                    break;
                }
                
                case BTN_LIMPIAR_CAJA: {
                    SetWindowText(GetDlgItem(VentCajas, EDT_NUMERO_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_BS_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_DOL_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_EUR_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_PES_CAJA), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_NOMBRE_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_APELLIDO_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_DIRECCION_ENCARGADO), L"");
                    SetWindowText(GetDlgItem(VentCajas, EDT_TELEFONO_ENCARGADO), L"");
                    break;
                }

                case BTN_EDITAR_CAJA:{

                    if (GetWindowTextLength(GetDlgItem(VentCajas, EDT_NUMERO_CAJA)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentCajas, EDT_NOMBRE_ENCARGADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentCajas, EDT_APELLIDO_ENCARGADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentCajas, EDT_DIRECCION_ENCARGADO)) == 0 ||
                        GetWindowTextLength(GetDlgItem(VentCajas, EDT_TELEFONO_ENCARGADO)) == 0 )
                    {
                        MessageBox(VentCajas, L"Todos los campos deben ser llenados", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    wchar_t buffer[100];
                    int numero_caja;
                    
                    
                        GetWindowText(GetDlgItem(VentCajas, EDT_NUMERO_CAJA), buffer, 100);
                        numero_caja = _wtoi(buffer);

                        int caja_encontrada = -1;
                        for(int i = 0; i < cant_cajas; i++){
                            if(d_cajas[i].numero_caja == numero_caja){
                                caja_encontrada = i;
                            }
                            
                        }

                        if(caja_encontrada == -1){
                            MessageBox(VentCajas, L"Caja no encontrada", L"Error", MB_ICONERROR | MB_OK);
                            break;
                        }

                        GetDlgItemText(VentCajas, EDT_NUMERO_CAJA, buffer, 100);
                        d_cajas[caja_encontrada].numero_caja = _wtoi(buffer);

                        GetDlgItemText(VentCajas, EDT_CEDULA_ENCARGADO, buffer, 100);
                        d_cajas[caja_encontrada].encargador.cedula_trabajador = _wtoi(buffer);

                        GetDlgItemText(VentCajas, EDT_NOMBRE_ENCARGADO, buffer,100);
                        wcscpy_s(d_cajas[caja_encontrada].encargador.nombre, 100, buffer);

                        GetDlgItemText(VentCajas, EDT_APELLIDO_ENCARGADO, buffer, 100);
                        wcscpy_s(d_cajas[caja_encontrada].encargador.apellido, 100, buffer);

                        GetDlgItemText(VentCajas, EDT_DIRECCION_ENCARGADO, buffer, 100);
                        wcscpy_s(d_cajas[caja_encontrada].encargador.direccion, 100,buffer);

                        GetDlgItemText(VentCajas, EDT_TELEFONO_ENCARGADO, buffer, 100);
                        d_cajas[caja_encontrada].encargador.telefono = _wtoi(buffer);


                        FILE *archivo_cajas = fopen("cajas.dat", "w");
                        if(archivo_cajas == NULL){

                            MessageBox(VentCajas, L"Error al abrir el archivo de cajas", L"Error", MB_ICONERROR | MB_OK);
                            break;
                        }

                        for(int i = 0; i < cant_cajas; i++){
                            for (int i = 0; i < cant_cajas; i++) {
                                fprintf(archivo_cajas, "Numero Caja: %d\n", d_cajas[i].numero_caja);
                                fprintf(archivo_cajas, "Monto Facturado en Bs.: %.2f\n", d_cajas[i].bolivares_facturados);
                                fprintf(archivo_cajas, "Monto Facturado en $: %.2f\n", d_cajas[i].dolares_facturados);
                                fprintf(archivo_cajas, "Monto Facturado en EUR: %.2f\n", d_cajas[i].euros_facturados);
                                fprintf(archivo_cajas, "Monto Facturado en PES: %.2f\n", d_cajas[i].pesos_facturados);
                                fprintf(archivo_cajas, "Cedula Encargado: %d\n", d_cajas[i].encargador.cedula_trabajador);
                                fprintf(archivo_cajas, "Nombre Encargado: %ls\n", d_cajas[i].encargador.nombre);
                                fprintf(archivo_cajas, "Apellido Encargado: %ls\n", d_cajas[i].encargador.apellido);
                                fprintf(archivo_cajas, "Direccion Encargado: %ls\n", d_cajas[i].encargador.direccion);
                                fprintf(archivo_cajas, "Telefono Encargado: %d\n", d_cajas[i].encargador.telefono);
                                fprintf(archivo_cajas, "---------------------\n");
                            }
                        }

                        fclose(archivo_cajas);

                        MessageBox(VentCajas, L"Informacion de la caja editada con exito", L"Exito", MB_OK);
                        
                        DestroyWindow(VentCajas);
                        HWND nVentCajas = CreateWindowEx(0, L"CL_VentanaCajas", L"Cajas", WS_OVERLAPPEDWINDOW, 15,15,950,700,NULL, NULL, instancia, NULL);
                        ShowWindow(nVentCajas, SW_SHOW);
                        UpdateWindow(nVentCajas);

                    break;
                }

                case BTN_ELIMINAR_CAJA:{

                    if (GetWindowTextLength(GetDlgItem(VentCajas, EDT_NUMERO_CAJA)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentCajas, EDT_CEDULA_ENCARGADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentCajas, EDT_NOMBRE_ENCARGADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentCajas, EDT_APELLIDO_ENCARGADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentCajas, EDT_DIRECCION_ENCARGADO)) == 0 ||
                    GetWindowTextLength(GetDlgItem(VentCajas, EDT_TELEFONO_ENCARGADO)) == 0 )
                {
                    MessageBox(VentCajas, L"Todos los campos deben ser llenados", L"Error", MB_ICONERROR | MB_OK);
                    break;
                }

                wchar_t buffer[100];
                int numero_caja;
                
                
                    GetWindowText(GetDlgItem(VentCajas, EDT_NUMERO_CAJA), buffer, 100);
                    numero_caja = _wtoi(buffer);

                    int caja_encontrada = -1;
                    for(int i = 0; i < cant_cajas; i++){
                        if(d_cajas[i].numero_caja == numero_caja){
                            caja_encontrada = i;
                        }
                        
                    }

                    if(caja_encontrada == -1){
                        MessageBox(VentCajas, L"Caja no encontrada", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    for(int i = caja_encontrada; i < cant_cajas-1;i++){
                        d_cajas[i] = d_cajas[i+1];
                    }
                    cant_cajas--;

                    FILE *archivo_cajas = fopen("cajas.dat", "w");
                    if(archivo_cajas == NULL){
                        MessageBox(VentCajas, L"Error al abrir el archivo de cajas", L"Error", MB_ICONERROR | MB_OK);
                        break;
                    }

                    for(int i = 0; i < cant_cajas;i++){
                        fprintf(archivo_cajas, "Numero Caja: %d\n", d_cajas[i].numero_caja);
                        fprintf(archivo_cajas, "Monto Facturado en Bs.: %.2f\n", d_cajas[i].bolivares_facturados);
                        fprintf(archivo_cajas, "Monto Facturado en $: %.2f\n", d_cajas[i].dolares_facturados);
                        fprintf(archivo_cajas, "Monto Facturado en EUR: %.2f\n", d_cajas[i].euros_facturados);
                        fprintf(archivo_cajas, "Monto Facturado en PES: %.2f\n", d_cajas[i].pesos_facturados);
                        fprintf(archivo_cajas, "Cedula Encargado: %d\n", d_cajas[i].encargador.cedula_trabajador);
                        fprintf(archivo_cajas, "Nombre Encargado: %ls\n", d_cajas[i].encargador.nombre);
                        fprintf(archivo_cajas, "Apellido Encargado: %ls\n", d_cajas[i].encargador.apellido);
                        fprintf(archivo_cajas, "Direccion Encargado: %ls\n", d_cajas[i].encargador.direccion);
                        fprintf(archivo_cajas, "Telefono Encargado: %d\n", d_cajas[i].encargador.telefono);
                        fprintf(archivo_cajas, "---------------------\n");

                    }


                    MessageBox(VentCajas, L"Caja eliminada exitosamente", L"Exito", MB_OK);


                    DestroyWindow(VentCajas);
                    HWND nVentCajas = CreateWindowEx(0, L"CL_VentanaCajas", L"Cajas", WS_OVERLAPPEDWINDOW, 15,15,950,700,NULL, NULL, instancia, NULL);
                    ShowWindow(nVentCajas, SW_SHOW);
                    UpdateWindow(nVentCajas);
                    break;
                }


            }
          break;
        }
           
        case WM_CLOSE: {
            DestroyWindow(VentCajas);
            break;
        }

        default: {
            return DefWindowProc(VentCajas, msg, wParam, lParam);
        }
    }

    return 0;
}

//=======================================================================================
//Funcion WinMain (Principal)
//=======================================================================================

int WINAPI wWinMain(HINSTANCE hInstancia, HINSTANCE hInstanciaPrevia, PWSTR pCmdLine, int nCmdShow) {
   CargarProductos();
   CargarClientes();
   CargarEmpleado();
   CargarFacturas();
   CargarCajas();

    //Inicializar Controles para el manejo de las listas
    INITCOMMONCONTROLSEX icex = {0};
    icex.dwSize = sizeof(icex);
    icex.dwICC = ICC_LISTVIEW_CLASSES;  // Tipos de controles: ListView
    InitCommonControlsEx(&icex);

    // VENTANA PRINCIPAL
    WNDCLASSEX clase  = {0};
    HWND ventana;
    MSG mensaje;

    clase.cbSize = sizeof(WNDCLASSEX);
    clase.cbWndExtra = 0;
    clase.cbClsExtra = 0;
    clase.style = CS_HREDRAW | CS_VREDRAW;
    clase.lpfnWndProc = VentanaPrincipal;
    clase.hInstance = hInstancia;
    clase.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    clase.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    clase.hCursor = LoadCursor(NULL, IDC_ARROW);
    clase.lpszClassName = L"MICLASE";
    clase.lpszMenuName = NULL;
    clase.hbrBackground = GetSysColorBrush(COLOR_WINDOW);

    //CLASE DE LA VENTANA PARA MOSTRAR LA LISTA DE LOS PRODUCTOS
    WNDCLASSEX ClaseProductos = {0};
    ClaseProductos.cbSize = sizeof(WNDCLASSEX);
    ClaseProductos.cbWndExtra = 0;
    ClaseProductos.cbClsExtra = 0;
    ClaseProductos.style = CS_HREDRAW | CS_VREDRAW;
    ClaseProductos.lpfnWndProc = VentanaProductos;
    ClaseProductos.hInstance = hInstancia;
    ClaseProductos.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    ClaseProductos.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    ClaseProductos.hCursor = LoadCursor(NULL, IDC_ARROW);
    ClaseProductos.lpszClassName = L"CL_LISTAPRODUCTOS";
    ClaseProductos.lpszMenuName = NULL;
    ClaseProductos.hbrBackground = GetSysColorBrush(COLOR_WINDOW);

    

//CLASE DE LA VENTANA PARA MOSTRAR LA LISTA DE LOS CLIENTES

    WNDCLASSEX C_VentListaClientes = {0};
    C_VentListaClientes.cbSize = sizeof(WNDCLASSEX);
    C_VentListaClientes.cbWndExtra = 0;
    C_VentListaClientes.cbClsExtra = 0;
    C_VentListaClientes.style = CS_HREDRAW | CS_VREDRAW;
    C_VentListaClientes.lpfnWndProc = VentanaClientes;
    C_VentListaClientes.hInstance = hInstancia;
    C_VentListaClientes.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    C_VentListaClientes.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    C_VentListaClientes.hCursor = LoadCursor(NULL, IDC_ARROW);
    C_VentListaClientes.lpszClassName = L"CL_VentanaCliente";
    C_VentListaClientes.lpszMenuName = NULL;
    C_VentListaClientes.hbrBackground =  GetSysColorBrush(COLOR_WINDOW);

    

    //CLASE PARA MOSTRAR LA LISTA DE LOS EMPLEADOS

    WNDCLASSEX C_VentanaEmpleados = {0};
    C_VentanaEmpleados.cbSize = sizeof(WNDCLASSEX);
    C_VentanaEmpleados.cbWndExtra = 0;
    C_VentanaEmpleados.cbClsExtra = 0;
    C_VentanaEmpleados.style = CS_HREDRAW | CS_VREDRAW;
    C_VentanaEmpleados.lpfnWndProc = VentanaEmpleados;
    C_VentanaEmpleados.hInstance = hInstancia;
    C_VentanaEmpleados.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    C_VentanaEmpleados.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    C_VentanaEmpleados.hCursor = LoadCursor(NULL, IDC_ARROW);
    C_VentanaEmpleados.lpszClassName = L"CL_VentanaEmpleados";
    C_VentanaEmpleados.lpszMenuName = NULL;
    C_VentanaEmpleados.hbrBackground =  GetSysColorBrush(COLOR_WINDOW);


    //CLASE DE LA VENTANA FACTURAS

    WNDCLASSEX C_VentanaFacturas = {0};
    C_VentanaFacturas.cbSize = sizeof(WNDCLASSEX);
    C_VentanaFacturas.cbWndExtra = 0;
    C_VentanaFacturas.cbClsExtra = 0;
    C_VentanaFacturas.style = CS_HREDRAW | CS_VREDRAW;
    C_VentanaFacturas.lpfnWndProc = VentanaFacturas; // Asegúrate de tener una función VentanaFacturas definida
    C_VentanaFacturas.hInstance = hInstancia;
    C_VentanaFacturas.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    C_VentanaFacturas.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    C_VentanaFacturas.hCursor = LoadCursor(NULL, IDC_ARROW);
    C_VentanaFacturas.lpszClassName = L"CL_VentanaFacturas";
    C_VentanaFacturas.lpszMenuName = NULL;
    C_VentanaFacturas.hbrBackground = GetSysColorBrush(COLOR_WINDOW);


   //CLASE DE LA VENTANA PRINCIPAL DE VENTAS

    WNDCLASSEX C_VentanaVentas = {0};
    C_VentanaVentas.cbSize = sizeof(WNDCLASSEX);
    C_VentanaVentas.cbWndExtra = 0;
    C_VentanaVentas.cbClsExtra = 0;
    C_VentanaVentas.style = CS_HREDRAW | CS_VREDRAW;
    C_VentanaVentas.lpfnWndProc = VentanaVentas; 
    C_VentanaVentas.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    C_VentanaVentas.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    C_VentanaVentas.hCursor = LoadCursor(NULL, IDC_ARROW);
    C_VentanaVentas.lpszClassName = L"CL_VentanaVentas";
    C_VentanaVentas.lpszMenuName = NULL;
    C_VentanaVentas.hbrBackground = GetSysColorBrush(COLOR_WINDOW);

   

    //CLASE DE LA VENTANA PRINCIPAL DE CAJAS

 WNDCLASSEX C_VentanaCajas = {0};
 C_VentanaCajas.cbSize = sizeof(WNDCLASSEX);
 C_VentanaCajas.cbWndExtra = 0;
 C_VentanaCajas.cbClsExtra = 0;
 C_VentanaCajas.style = CS_HREDRAW | CS_VREDRAW;
 C_VentanaCajas.lpfnWndProc = VentanaCajas; 
 C_VentanaCajas.hInstance = hInstancia;
 C_VentanaCajas.hIcon = LoadIcon(NULL, IDI_APPLICATION);
 C_VentanaCajas.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
 C_VentanaCajas.hCursor = LoadCursor(NULL, IDC_ARROW);
 C_VentanaCajas.lpszClassName = L"CL_VentanaCajas";
 C_VentanaCajas.lpszMenuName = NULL;
 C_VentanaCajas.hbrBackground = GetSysColorBrush(COLOR_WINDOW);

// CLASE DE LA VENTANA PARA CREAR FACTURAS
WNDCLASSEX C_VentanaCrearFactura = {0};
C_VentanaCrearFactura.cbSize = sizeof(WNDCLASSEX);
C_VentanaCrearFactura.cbWndExtra = 0;
C_VentanaCrearFactura.cbClsExtra = 0;
C_VentanaCrearFactura.style = CS_HREDRAW | CS_VREDRAW;
C_VentanaCrearFactura.lpfnWndProc = VentanaCrearFactura;
C_VentanaCrearFactura.hInstance = hInstancia;
C_VentanaCrearFactura.hIcon = LoadIcon(NULL, IDI_APPLICATION);
C_VentanaCrearFactura.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
C_VentanaCrearFactura.hCursor = LoadCursor(NULL, IDC_ARROW);
C_VentanaCrearFactura.lpszClassName = L"CL_VentanaCrearFactura";
C_VentanaCrearFactura.lpszMenuName = NULL;
C_VentanaCrearFactura.hbrBackground = GetSysColorBrush(COLOR_WINDOW);

// CLASE DE LA VENTANA PARA MOSTRAR FACTURAS
WNDCLASSEX C_VentanaMostrarFactura = {0};
C_VentanaMostrarFactura.cbSize = sizeof(WNDCLASSEX);
C_VentanaMostrarFactura.cbWndExtra = 0;
C_VentanaMostrarFactura.cbClsExtra = 0;
C_VentanaMostrarFactura.style = CS_HREDRAW | CS_VREDRAW;
C_VentanaMostrarFactura.lpfnWndProc = VentanaMostrarFactura;
C_VentanaMostrarFactura.hInstance = hInstancia;
C_VentanaMostrarFactura.hIcon = LoadIcon(NULL, IDI_APPLICATION);
C_VentanaMostrarFactura.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
C_VentanaMostrarFactura.hCursor = LoadCursor(NULL, IDC_ARROW);
C_VentanaMostrarFactura.lpszClassName = L"CL_VentanaMostrarFactura";
C_VentanaMostrarFactura.lpszMenuName = NULL;
C_VentanaMostrarFactura.hbrBackground = GetSysColorBrush(COLOR_WINDOW);



    //REGISTRAR TODAS LAS CLASES CREADAS

    if (!RegisterClassEx(&clase)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }

    if (!RegisterClassEx(&ClaseProductos)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }

    if (!RegisterClassEx(&C_VentListaClientes)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }

    if (!RegisterClassEx(&C_VentanaEmpleados)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }
     
    if (!RegisterClassEx(&C_VentanaVentas)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }

    if (!RegisterClassEx(&C_VentanaFacturas)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }
    
   if (!RegisterClassEx(&C_VentanaCrearFactura)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }
    
    if (!RegisterClassEx(&C_VentanaMostrarFactura)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }
    
    if (!RegisterClassEx(&C_VentanaCajas)) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }
    
    ventana = CreateWindowEx(0, L"MICLASE", L"HIPERMERCADO CACHAMAY", WS_OVERLAPPEDWINDOW, 350, 10, 800, 600, HWND_DESKTOP, NULL, hInstancia, NULL);

    if (ventana == NULL) {
        MessageBox(NULL, L"HA OCURRIDO UN ERROR", L"ERROR", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }

    ShowWindow(ventana, nCmdShow);
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while (GetMessage(&mensaje, NULL, 0, 0) > 0) {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }

    return (mensaje.wParam);
}
