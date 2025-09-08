///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 01 - Introduction to C++ Programming Language
******************************************************************************/
/******************************************************************************
** Education

Nasıl bir programlama dilidir?
  lamda expressions
  Multi-paradigm
  Prosedürel programlama
  Nesne yönelimli / nesne tabanlı
  Generic (türden bağımsız programlama)
  Functional programming

Data abstraction (for C struct)
Efficient - Friendly language (Programcının verimliliği değil, programın
verimliliğini ister) C / C++ Arasındaki farklar ill-formed / well-formed syntax
error invalid code / valid code illegal code / legal code undefined behavior
(ub) Otomatik ömürlü değişkeni değer atamadan kullanmak NULL pointer direference
etmek Dizileri taşırmak… unspecified behavior Satırın okunma sırası aynı değeri
farklı değişkenlerde kullanıyor. Adresi aynı olmayabilir implementation defined
derleyiciye stabil bir çıktı üretmeye zorlar
char, int, etc. (signed/unsigned olmadığı durumlarda bilinemez)
implicit (implicit int C’de var CPP’da yok)
implicit (Örtülü - kapalı - gizli)
implicit int (türü yazılmadığın durumda işaretli int türü yazıldığı düşünülür)
explicit (açık, cast edilmiş)
implicit/explicit func decleration
Fonksiyon
int func(); === int foo(void);

illegal aktivite
for(int i = 0; i < 10; i ++)
{
    int i  = 99; // CPP'de illegal
}

Türlere ve tür dönüşümlerine ilişkin farklar
bool tür değişkeni int değerindeki 0 (false) ya da 0’dan büyük sayıları (true)
değerlendirir. Adres türlerinden pointer türlerine otomatik dönüşümlerde u
dönüşüm x1 conversion var mı? EVET. int * gp; int x = 100; int* ptr = &x; bool
b1 = ptr; //Doğrudur | true döner bool b2 = gp; //Doğrudur | false döner

Bool’dan int türüne dönüşüm
bool flag = true;
bool is_on = false;


int x = flag; // x = 1
int y = is_on; // y = 0
int *ptr = is_on // Bool'dan int türüne dönüşüm yoktur.

user-defined type (kullanıcının oluşturduğu türlerdir)
struct Data {
    int a, b, c;
}
struct Data mydata;

// ya da

typedef struct Data {
    int a, b, c;
}Data;
Data mydata;

struct Data {
    // C'de en az bir elemanı olması gerekiyor.
    // CPP'de eleman olması gerekmiyor.
}

const anahtar sözcüğüne ilişkin farklar
const nesnesine ilk değer verilmelidir.
const olarak tanımlanmış nesnelerin oluşturduğu ifadeler
const - constexpr - consteval farklı ifadelerdir.
Linkage
Aynı isim birden fazla kaynak dosyasında aynı anlamda kullanılırsa (extern
linkage) Aynı isim birden fazla kaynak dosyasında farklı anlamda kullanılırsa
(internal linkage) CPP dilinde global const nesneler int-linkage, C’de
ex-linkage’dir. Scope leakage Değişkenin kullanılacağı alan dışında o isim
görünür, bilinir durumdaysa olur. int i; for(i = 0; i < 10; i ++){ ; }

Aşağıdaki i C’de geçerli, CPP’de geçersizdir. Name masking / shadowing / hidding
olduğu için içteki i ifadesi, döngüdeki i ifadesini gizliyor. for(int i = 0; i <
10; i ++){ int i = 99;
    }

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 02 - Değişken tanımlamaları
******************************************************************************/
/******************************************************************************
** Education

Function overloading için önemli bir husus:
'A' : Karakter sabitlerinin türü char'dır. 1 byte'dır.
"Akif" : Char dizisidir. char[5]. array decay
Array to pointer conversion

Statement (deyim)
Expression (ifade)
data type ve value category (l or r value expression)
Lvalue: O ifadenin bellekte tutulan bir nesneye karşılık gelmesidir. Nesne
gösteren bir ifade örneğidir. Rvalue: Bellekte doğrudan kalıcı yeri olmayan,
ancak bir hesaplamaya yönelik bir ifadedir. İfadeye ilk değer vermek için
oluşturulabilir. 3 tane value category vardır. R-L-X value Reference semantics
Initialization types
int main() {
    std::string s3 = "hello"; // copy-initialization
    std::string s3; 	     // default-initialization
    std::string s4("hello");  // direct-initialization
    std::string s5{'a'};      // list-initialization
}

Most vexing parse
Öyle bildirimler var ki, nesne tanımlama (object instantiation)
fonksiyon bildirimi (function declaration)
İsmi bx değişken tanımladım derken, aslında bir fonksiyon tanımlanmış oldu.
struct A {


};
struct B {
    B(A);
};
int main() {
    B bx(A());
}

Value-initialization
int x{4};   // direct-init
int y{};    // value-init

const nesnelere ilk değer verilmesi zorunludur. const nesneler default-init
edilemez. type deduction (Tür çıkarımı) Derleyicinin koda bakarak değişkenin
türünü belirler. compile-time (Derleyici koda bakarak kodları üretiyorsa
static’tir.) running-time (Programın çalışma zamanında kodları üretiyorsa
dynamic’tir) Reference Semantic Referans pointer’lara sadece dil katmanında bir
alternatif sunar.

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 03 - Reference Schemantic, Scope and C/C++ Differents
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT: 
* Referans Semantiği:
  L-value Reference
  R-value Reference
  Universal Reference

* Expression: İfadelerin kendisidir. a, a + 10, 10
* Data type: İfadelerin veri tipidir. int, char, long
* Value category: İfadelerin L & R Value expression kavramıdır
  L-value Expression: İfade, bir nesneye karşılık geliyor.
  R-value Expression: İfade, bir nesneye karşılık gelmiyor. Değer üretiyor.

* Primary Value Categories:
  L-value   -> L value        -> T
  PR-value  -> Pure R value   -> T&
  X-value   -> eXpiring value -> T&&

* 
  int x = 10;
  int y = 20;
  int& r = x; -> r x'e bir referanstır.
  
  r = 45;   -> x = 45;
  ++r;      -> ++x;
  r = y;    -> x = y;
  
***

1- C / C++ scope farkları
  C'de
    block scope
    file scope
    function prototype scope
    function scope

  C++'da
    block scope
    namespace scope
    class scope
    function prototype scope
    function scope

2- Name lookup
  Qualified name
    '::' olarak operatör tanımlanır.
    x değeri hem değişken hem fonksiyon ise, ::x uygun olanı seçer.

3- Expression / Statement
  Yazılın ifade, dilin kurlların göre geçerli ise ";" kullanılrak deyim haline
gelir. Yan etkisi olan bir ifadeyi "(void)" olarak cast'leyebilirsin.

  Data Type?
    İfadenin türünü belirtir. Int, double, long, char, etc.

  Value Category?
    Lvalue, Rvalue, Xvalue
    Primary value categories
      pr  L  X
    Secondary value categories
      R  GL

    Value  C  C++
    +x     R   L
    ++x    R   L
    --y    R   L
    a, b   R   L
    ? :    R   L

  Source file : Önişlemci programının çalışmasından önceki dosya durumudur.
    include, define komutları vs olur.
  Translation unit : Önişlemci programı çalışmış. Derleyicinin gördüğü koddur.

  Constant Expression
    Bir ifadenin değeri, derleyici tarafından derleme zamanında net olak
biliniyor. 17 + 5 (constant expression)

    int a[const exp]: dizi boyutu gösteren ifadeler
    Global değişkenlere ilk değer veren ifadeler
    case ifadeleri

  Short Circuit Behavior

  Sequence point (sequencing point)
    statement;
    int x = 5, y = ++x, z = y + x;
    if(expr), while(expr), for(;;), switch(expr)

  Order of evaluation


******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 04 - Reference Schemantic && auto
******************************************************************************/
/******************************************************************************
** Education

*** Trailing return type
*** auto return type

auto func(void) -> int (*)(int, int); <<==>> int(*func())(int, int);

*** MÜLAKAT: foo func. a'yı döndürsün.
foo()
{
  static int a[10]{};
}

auto foo()-> int(&)[10]
{
  static int a[10]{};
  return a;
}
***

struct Data {
  int x, y, z;
};

Data& bar(Data& r)
{
  ++r.x;
  ++r.y;
  ++r.z;
  return r;
}

int main()
{
  Data mydata{1, 5, 7};
  Data& dr = bar(mydata); //dr mydata ile bağlanmıştır.
  
  std::cout << dr.x << dr.y << dr.z << std::endl;
}

*** MÜLAKAT:
Pointer semantiği: Default initialize olur
Referans semantiği: Default initialize olmaz.

Pointer semantiği: NULL Pointer var.
Referans semantiği: NULL Referans yok.
***

*** MÜLAKAT:
Derleme Zamanı mı Çalışma Zamanı mı?
Function overloading -> Derleme zamanı ile alakalı bir kavram
Virtual Dispacht -> Run-time ile alakalı bir kavram
***

*** MÜLAKAT:
Auto anahtar sözcüğü:
* Tür çıkarımı auto için yapılır.
* "auto" için initializer gerekiyor. İlk değer olması mecburidir.
* Tür çıkarımı dış kümeyi içerir. int mi double mı? Tabii ki double.
***

*** MÜLAKAT:
Reference collapsing:
* Referansın referansı olmadığı için L value yapar.
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 05 - Decltype & Default Argument
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT:
* Eğer ilk değer veren ifadenin değer kategorisi L value ise
  o zaman auto için yapılan çıkarım sol taraf referansı türüdür.
  auto &&r = x;

* R value ise referans olmayan türüdür.
***

*** MÜLAKAT:
Decltype Specifier:
* decltype(expr) -> Compile-time'da tür elde ediyor.

* Tür bilgisidir. Türü kullandığın yerde kullabilirsin.

* decltype specifier ile yapılan tür çıkarımında iki ayrı kural seti vardır.
  1. kural seti:
  decltype(a.b) -> isim olması ya da .-> ile erişilmiş olası
  2. kural seti:
  decltype(10)  -> değişken türü isim olmayan bir ifade olmasıdır. decltype((a))
***

*** MÜLAKAT:
* Decltype 1. kuralı: const default initialize edilemez.
  int x = 5;
  int& r{x};
  decltype(r) x; -> referanslar default initialize edilemezler.

* int a[5]{};
  decltype(a)b = a; -> syntax hatası vardır. a = int[5]
***

*** MÜLAKAT:
* Decltype 2. kuralı: ifade ve exp olduğunda değer kategorisine bağlıdır.
* PR -> T    -> Geri dönüş türü referans olmayan PR'dır.
  L  -> T&   -> Geri dönüş türü sol referans olan L'dir.
  x  -> T&&  -> Geri dönüş türü sağ referans ise X'dir.

* int x = 10;
  decltype(x + 5); -> PR

* int x{ 435};
  decltype(x++)r = 10; -> syntax hatası yoktur.

* int x = 10;
  int y = 20;
  decltype(x)a = y; -> 1. kural seti
  decltype((x))b = y; -> 2. kural seti
***

*** MÜLAKAT:
* int* ptr = nullptr;
  auto x = *ptr; -> UB olmaz.

* int a[5]{};
  int ival = 72;
  auto b = a[5];
  int x = 98;
  int y;

  auto c1 = a[5];     -> UB
  auto c2 = y;        -> UB
  auto c3 = ival << x;-> UB
  sizeof(anything);   -> UB Değildir.
***

*** MÜLAKAT:
* Default Argument
* Minimum bir argüman verilmelidir.
  Değişken türü başlatıcıdır. int, char* vs.
  NULL pointer kullanıldığı yerde fonksiyon biter.
  void foo(int, ...);
***

*** MÜLAKAT:
* Maximal munch kuralı: en uzun atomu çekecek a+++b -> a++ + b olarak tanır.
  int a = 10;
  int b = 40;
  int c = a+++b;
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 06 - Constexpr & Odr
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT:
* constexpr sadece tanım olarak vardır.
  const ile tanımlanırsa başta constexpr yazmaya gerek yok.
  Derleme zamanında sabit olarak alınması gerekiyor.
***

*** MÜLAKAT:
* constexpr functions.
  static ömürlü yerel değişkene sahip olmayacak

  constexpr int foo(int x)
  {
    return x * x;
  }

* Eğer tüm params sabit ifadeleri ile çağrılırsa,
 dönüş değeri compile-time'da elde edilir.
 
* ÖZET olarak, macro ifadeler gibi run-time meşgul edilmez. sin, cos gibi...
***

*** MÜLAKAT:
* ODR: Only Definition Rule
  Değişkenler, sınıflar, fonksiyonlar -> Birden fazla tanım olmamalıdır.

  int x = 5;
  int x = 5; -> ODR ihlal edilmiştir.

  Farklı file'larda global ise -> ODR ihlal edilmiştir. Linker tespit eder.
  Farklı file'larda private ise -> ODR ihlal edilmemiştir. Linker tespit etmez.
***

*** MÜLAKAT:
* Optimizasyonlar:
  Inline fonksiyon ODR ihlal etmediği anlamına geliyor.

  Farklı file'larda global ise -> ODR ihlal edilmiştir. Linker tespit eder.
  Farklı file'larda global ise -> ODR ihlal edilmemiştir. Linker tespit etmez.

* ODR ihlalleri:
  Struct, Class definitions ihlal etmez.
  Statik ömürlü global değişken & statik ömürlü sınıfların statik veri elemanları
***

*** MÜLAKAT:
* Underlying-type (baz tür)
  C++ dilinde (modern C++ öncesi)
  enum türlerinin istenmeyen özellikleri

* Derleyiciye bağlı olduğu için enum türleri başlık dosyalarında incomplete typedır.
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 07 - Enumaration Types & Type-Cast Operators
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT:
* scoped enumaration.
  enum class traffic_light_e { red, yellow, green};
  enum class screen_light_e { red, yellow, green}; -> Benzer enumlar hata vermez.
***

*** MÜLAKAT:
* Mülakat sorusu:

void func(int x)
{
  int func = 40; -> Syntax hatası bulunmuyor.
  
  func(45); -> Hatalı.
  ::func(45); -> Hatasız. Recursive bir çağrı olacaktır (Kendisini çağırıyor)
}
***

*** MÜLAKAT:
* Casting

* static_cast -> reel değerler arası tür dönüşümü için yapılmaktadır.
  double c = static_cast<double>(a)/b;

* const_cast -> const olandan olmayana çevirmelerde kullanılır.
  int x {56};
  const int* cp = &x;
  int* ptr = const_cast<int *>(cp);
  
* reinterpret_cast -> int adresini char dönüşümü yapmak için kullanılır.
  ifs.read(reinterpret_cast<char*<(a), sizeof(int)*10);

* dynamic_cast
  ----
***

*** MÜLAKAT:
* C++ Attributes (C++ Niteliği)
  [nodiscard]     -> eğer dönüş değeri bizim için önemli ise kullanılır.
  [fallthrough]   -> switch deyiminde ; break; kısımlarında kullanılır.
  [maybe_unused]  -> Çoğunlukla kullanılmayan fonksiyonlar, assert'ler içindir.
  [likely]        -> Alternatif yürütme metodudur.
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 08 - Function Overloading
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT:
* Function overloading -> Derleme zamanında fonksiyon işlenir.
  Yazılan iki fonksiyonda da herhangi bir çakışma olmadığı düşünülmektedir.
  Fonksiyon parametresi pointerların bildirilmesi.

* Function overloading mi?
void func(int* ptr);
void func(int* const ptr); -> Overloading vardır.
void func(intconst * ptr); -> Overloading yoktur.
***

*** MÜLAKAT:
* Overloading var mıdır?

* int*, int[]                               -> redeclaration

* int(int), int(*)(int)                     -> redeclaration

* int(*)[10], int(*)[29]                    -> overloading

* int**, int* []                            -> redeclaration

* int, typedef int nec                      -> redeclaration

* int, int32_t                              -> opsiyonel, derleyiciye bağlı

* char, signed char, unsigned char          -> 3'ü de overloading

* int &, int &&, const int &, const int &&  -> 4'ü de overloading

* int*, int&                                -> overloading
***

*** MÜLAKAT:
* Candidate -> Aday fonksiyon (Benzer isimli fonksiyonları not alır)

* Viable function -> Uygun fonksiyon (Tek çağrıldığında legal olmalıdır)
  void* -> int* dönüşüm olmaz!
***

*** MÜLAKAT:
* Conversion'lar için en uygun function overloading seçilmesi
***

*** MÜLAKAT:
* Const Overloading

* T*, const T* -> x değeri const ise const, değilse const olmayan çağrılır.
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 09 - Classes
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT:
* Classes


* Access controls
  public members
  private members
  protected members
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 10 - Class Devam
** Const Member Functions
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT:
* this keyword
  this bir anahtar sözcüktür.
  this bir pointer'dır. Üye fonksiyonun adresini verir.
  non-static üye fonksiyonları için kullanılır.

* front -> ilk nesneyi referans alır.
  back -> son nesneyi referans alır.

* Üye fonksiyonu içinde fonksiyonun gizli parametre değeri değişkeni bir adres,
  bir pointerdır. Global bir fonksiyona gönderecekseniz...
  Yani bu fonksiyon nesne için çağrıldıysa o nesnenin adresini (kendisini)
  global bir fonksiyona gönderecekse "this pointer" kullanılmalıdır.

***

*** MÜLAKAT:
* const member functions (Const olması gereken her şey const olacak)

* const üye fonksiyonlar içinde sınıfın non-static veri elemanlarına atam yapamayız

* const üye fonksiyonlar içinde sınıfın non-const üye 

***

*** MÜLAKAT:
* Savaşçının yaşı değiştiğinde, string değişir mi?
  class Fighter {
  public:
    std::string m_name;
    int m_age;
    int power;
    
  }
  Cevap -> Değişir.
***

*** MÜLAKAT:
* Savaşçının yaşı değiştiğinde, string değişir mi?
  class Fighter {
  public:
    void foo()const
    {
      m_age ++; -> HATA MIDIR? Evet!
      power *= 2; -> HATA MIDIR? Evet!

      ++debug_call_count; -> HATA MIDIR? Hayır!
    }
  private:
    std::string m_name;
    int m_age;
    int power;
    mutable int debug_call_count; -> Değer değişimi class statement değiştirmez.

  }
  Cevap -> Değişir.
***

#include <math.h>
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 11 - Constructor & Destructor & Special Member Functions
******************************************************************************/
/******************************************************************************
** Education

*** MÜLAKAT:
* Constructor
  Sınıf ismiyle aynı isme sahip olacak.
  Sınıfın non-static member function olacak (Global/statik olamaz)
  Fonksiyon const member function olamaz.
  Fonksiyon ctor'ları birden fazla olabilir (overload: int, int int, ...)
  Fonksiyonlar public olmak zorunda değildir. private, protect olabilir.
  Sınıfın ctorları . ya da -> ile çağrılamaz.
  Sınıfın üye fonksiyonunun çağrılması ile hayatını yapıcı yapıyor.
  Geri dönüş olmayan fonksiyonları void değildir.

* Default Constructor
  Parametresi olmayan ya da tüm parametreleri default arg. alan ctorlardır.

* Destructor
  Sınıf nesnesinin hayatını sonlandırır.
  Sınıfın üye fonksiyonunun çağrılması ile hayatını sonlandırır.
  Sınıf olarak tek bir tane dtor olmalıdır. parametre almaz.

*** MÜLAKAT:
  * Sınıfların special member function'ları nelerdir?
  * 
  * Default ctor
  * destructor
  * copy ctor 
  * move ctor
  * copy assignment
  * move assignment
  * 
  * Çünkü bu fonkların kodlarının (belirli koşullar sağlandığında)
  * derleyici tarafından bizim için yazılabilmesine = default etmesi denir.
***

*** MÜLAKAT:
  * RAII nedir?
  * RAII kullanımına örnek veriniz.
  * 
***

* Storage duration:
  * Automatic storage class: 
  * Static storage class: 
  * Dynamic storage class: 
  * Thread-local storage: 

* Global sınıf nesnesi:
  * main çalışmadan önce hayata başlıyor.
  * ctor içinde gizli parametre değişkeni vardır.
  * 

*** MÜLAKAT:
  * Aynı kaynak dosyada tanımlanan global değişkenlerin ctor çağrılması
  * belirli bir sıraya dahildir.
  * 
  * Static initialization fiasco: Aynı programın farklı kaynak dosyalarında
  * tanımlanan global sınıf nesnelerinin ctor'larının çağrılma sırası
  * dil tarafından belirlenmemiştir.
  * 
***

* ctor (member) initializer list
  * Sınıfın ctor'ının, sınıfın non-static veri elemanlarını initialize etme sentaksıdır.
  * Yani bir sınıfın non-static veri elemanlarını initalize etmek istiyorsak
  * sınıfın ctor için member initializer list
  * 

*** MÜLAKAT:
  * 
class Myclass {
public:
    myclass()
    {
        mx = 0; ///< Atama yapılır. Ama yapmayın!
        my = 0; ///< Atama yapılır. Ama yapmayın!
    }

private:
    int mx, my; ///< mx ve my elemanlarını initialize edilir.
};
  * 
***

*** MÜLAKAT:
  * Class içindeki elemanların initialize işlemi aşağıdakilerin hangisinde yapılır?

class Myclass {
public:
    myclass() : my(10), mx(20)      ///< Ctor initialize list sırasında mıdır?
    {

    }

private:
    int mx, my;                     ///< Bildirimdeki sırada mıdır?
};
  * Cevap: BİLDİRİMDEKİ SIRADADIR.
***


******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 12 - Copy Constructor (Cc Ya Da Cctor) & Value Semantics
******************************************************************************/
/******************************************************************************
** Education

* Sınıfların özel üye fonksiyonları hangileridir? Özel olmasını sağlayan nedir?
  * Default ctor
  * dtor
  * copy ctor
  * move ctor
  * copy assignment
  * move assignment
  * 

* Bir sınıfın special member function statüleri:
  * not declared        ///< ctor bildirilirse, default ctor not declared.
  * user declared       ///< Özel üye func. programcı bildirir. default or delete
  * implicitly declared ///< Özel üye func. bildirilmese de örtülü olarak bildirilir.
  * 

* Copy Ctor
  * Sınıfın copy ctor'ı sınıf nesnesi hayata getirilirken aynı sınıf türünden
  *   başka bir sınıf nesnesiyle onu initialize etmek gerekiyor.
  *   Bu durumda hayata gelen sınıf nesnesi için copy ctor çağrılacak.
  *   Ona ilk değer veren nesneye de copy ctor parametresi olan referansa bağlanacak.
  * 

*** MÜLAKAT: Sınıfın özel üye funcs. ne yapıyorsun?
  * Sınıfın, özel üye funcs. derleyici tarafından ne zaman ve nasıl yazıldığı bellidir.
  * Buna "Rule of Zero" denir. Derleyici uğraşsın, banane?
  * 
  * Fakat default ctor biz yazmak zorundayız.
  * Çünkü sınıfın non-static veri ögeleri garbage değer alabilir. UB oluşturur.
  * 
***

* Value type & value semantics
  * Her nesnenin değeri kendinedir.
  * x = y ataması yapıldığında, x ve y eşit olacak. Herhangi bir ilişki kalmayacak.
  * 

*** MÜLAKAT: String sınıfı bir value type mıdır?
  * Evet value type'dır.
  * Her değişkenin değeri kendinedir.
  * 
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 13 - Copy Assignment & Move Constructor & Assignment
******************************************************************************/
/******************************************************************************
** Education

* Copy Assignment
  * non-static member func.
  * x = y değerlemesinde -> x.copy_assignment(y) olmaktadır.
  * x: copy assignment içindeki this pointer'inin adresidir.
  * y: func. parametresine arguman olarak gönderilecek.
  * 
  * non-static public inline üye func. olmak zorundadır.
  * 
  * dtor -> release resources
  * copy ctor -> deep copy
  * copy assignment -> release resources
  * 
  * Myclass& operator = (const Myclass &); -> copy assignment
  * 


* Move ctor
  * copy ctor -> L-Value
  * move ctor -> R-Value
  * 
  * Myclass(const Myclass&);  -> copy ctor
  * Myclass(Myclass&&);       -> move ctor
  * 
  * Myclass& operator = (Myclass &&); -> move assignment
  * 


*** MÜLAKAT: Myclass move ve copy ctor vardır. Çalışınca copy mi move mu çağrılır?
  * 
class Myclass {
public:
  Myclass() = default;              ///< Default ctor

  Myclass(const Myclass&) ///< copy ctor
  {
    std::cout << "copy ctor\n";
  }

  Myclass(Myclass&&) ///< move ctor
  {
    std::cout << "move ctor\n";
  }

};

void func(const Myclass&)
{
  std::cout << "const Myclass&\n";
}
void func(Myclass&&)
{
  std::cout << "Myclass&&\n";
}

int main()
{
  Myclass m;
  func(std::move(m));
}
  * 
  * Cevap: Hiçbiri çağrılmaz.
***


* Genel özet:
  * İster L-Value olsun : Myclass &r
  * İster R-Value olsun : Myclass &&rr
  * 
  * Referans değişkeni varsa,
  * O referans değişkeni oluşturduğu isim her zaman : L-Value'dur 
  * 

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 14 - Temporary Objects (C++17 İle Kuralları Çok Değişti) & Life Extension
** Moved-From State & Conversion Constructor & Explicit Ctor
******************************************************************************/
/******************************************************************************
** Education

+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
|               | default ctor  | destructor    | copy ctor     | copy assign   | move ctor     | move assign   |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| hiçbiri       | defaulted     | defaulted     | defaulted     | defaulted     | defaulted     | defaulted     |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| constructor   | not declared  | defaulted     | defaulted     | defaulted     | defaulted     | defaulted     |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| default ctor  | user declared | defaulted     | defaulted     | defaulted     | defaulted     | defaulted     |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| destructor    | defaulted     | user declared | defaulted     | defaulted     | not declared  | not declared  |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| copy ctor     | not declared  | defaulted     | user declared | defaulted     | not declared  | not declared  |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| copy assign   | defaulted     | defaulted     | defaulted     | user declared | not declared  | not declared  |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| move ctor     | not declared  | defaulted     | deleted       | deleted       | user declared | not declared  |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
| move assign   | defaulted     | defaulted     | deleted       | deleted       | not declared  | user declared |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+


* Constructor Structures
  * default ctor : Herhangi bir ctor belirlenmezse derleyici belirler.
  * destructor : Her zaman vardır.
  * 


* move-only type
  * move ctor ve assignment yapılıyor ama copy ctor ve assignment hata veriyor.
  * Asla move member'ları delete etmeyiniz.
  * 


* Yeni konular
  * temporary objects : İsmi olmayan nesnelere verilen isimdir.
  * explicit ctor     : 
  * conversion ctor   : 
  * 


* 
  * Normalde bir geçici nesne oluştuğunda, hayata gelen geçici nesnenin
  *     hayatı geçici nesneyi içine alan ifadenin yürütülmesiyle sona erer.
  * 
  * Tipik olarak (böyle bir zorunluluk yoktur)
  *     move member'lar
  *     kaynağı çalınmış diğer nesneyi
  *     default ctor edilmiş state'te bırakır.
  * 


* Moved-From State
  * Kaynağı çalınmış bir nesne
  *     a) Geçerli bir durumda (in a valid state)
  *     b) It's value unknow
  * 


* Conversion Constructor
  * Dönüştüren kurucu işlevidir.
  * Sınıfların (özellikle tek parametreli ctor'ları) varlık nedenlerinin yanı sıra
  *     sınıf türünden olmayan bir ifadeyi sınıf türüne dönüştürme görevini gerçekleştirir.
  * 
  * Örnek:
class Myclass {
public:
    Myclass() = default;
    Myclass(int x)
    {
        std::cout << "Myclass(int x) x" << x << "\n";
        std::cout << "this = " << this << "\n";
    }
    
    ~Myclass()
    {
        std::cout << "Myclass dtor this =" << this << "\n";
    }

};

int main()
{
    Myclass mx;

    mx = 5;
}
  * 


* Değerlendirme
  * Eğer bir dönüşüm aşağıdaki dönüşüm sekanslarından biriyle gerçekleştirilebiliyor ise
  *     derleyici bu dönüşümü örtülü olarak yapmak zorundadır.
  * 
  * user-defined conversion + standard conversion
  * standard conversion + user defined conversion
  * 


* Explicit ctor
  * Bir sınıfın (özellikle) tek parametreli ctor'larını
  *     (aksi yönde karar almanızı gerektirecek makul bir neden olmadıkça)
  *     explicit yapınız!!!
  * 
  * explicit -->> explicit only!!!
  * 
  * Örnek:
class Myclass {
public:
    Myclass();
    explicit ~Myclass(int);

};

int main()
{
    Myclass m;
    m = 23; ///< Illegal
}
  * 

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 15 - Copy Elision & Dinamik Ömürlü Nesneler & New & Delete
******************************************************************************/
/******************************************************************************
** Education


class Myclass {
public:
    Myclass()
    {
        std::cout << "default ctor\n";
    }
        
    ~Myclass()
    {
    std::cout << "destructor\n";
    }
    
    explicit Myclass(int)
    {
        std::cout << "Myclass(int)\n";
    }

    Myclass(const Myclass&)
    {
        std::cout << "copy ctor\n";
    }
 
    Myclass (Myclass&&)
    {
        std::cout << "move ctor\n";
    }

    Myclass& operator= (const Myclass&)
    {
        std::cout << "copy assignment\n"; return *this;
    }

    Myclass& operator=(Myclass&&)
    {
        std::cout << "move assignment\n";
        return *this;
    }
};


* Temporary Materialization
  *  Bir sınıf nesnesi olmamasına rağmen bir sınıf nesnesini oluşturmayı
  *     zorunlu kılan senaryolara denir.
  * 
  * PR-Value'dan XR-Value dönüşüm olur.
  * 
  * Örnek:
foo(Myclass[46]);

Cevap: int parametreli ctor ve dtor çağrılıcak.
  * 
  * Bu duruma geçici bir nesnenin bir fonksiyonda çağrılması denir.
  * 


* Return Value Optimization (RVO)
  * Bir fonksiyon, nesne döndürürken genellikle bir kopyalama işlemi yapar.
  *     Ancak bu kopyalama maliyetli olabilir.
  *     RVO, derleyicinin bu kopyalamayı optimize ederek kaldırmasıdır.
  * Örnek:
MyClass createObject() {
    return MyClass(10); // normalde burada ctor + copy ctor çağrılır
}
  * Geçici nesne dönerken kopyalamayı engeller
  * 


* Named Return Value Optimization (NRVO)
  * RVO’nun bir isimlendirilmiş nesne versiyonudur.
  *     Yani döndürülen nesne geçici değil,
  *     fonksiyon içinde isimlendirilmiş bir değişkense bile
  *     derleyici kopyalamayı atlayabilir.
  * Örnek:
MyClass createObject() {
    MyClass obj(10);  // isimlendirilmiş nesne
    return obj;       // NRVO burada devreye girebilir
}
  * İsimlendirilmiş nesne dönerken kopyalamayı engeller
  * 


* Copy Elision
  * Temporary object passing (mandatory):
  *     Bir fonksiyon parametresi sınıf türünden ve
  *     biz onu geçici nesne ile çağırıyor.
  * 
  * Returning a temporary object (mandatory):
  *     Bir fonksiyon geçici nesne döndürüyor.
  * 
  * Returning an object of automatic storage class (optimization):
  *     Bir fonksiyonda yerel (otomatik ömürlü) bir nesne oluşturup onu döndürüyor.
  * 


* Dinamik Ömrülü Nesneler
  * Static Storage Class : 
  *     static anahtar sözcüğü ile tanımlanan değişkenler ve global değişkenler.
  *     Global nesneler
  *     Static yerel nesneler
  *     Sınıfların static veri elemanlar (static data members)
  * 
  * Automatic Storage Class : 
  *     Varsayılan ömür. Bir blok (scope) içinde tanımlanan yerel değişkenler.
  *     Parameters
  *     Local variable
  * 
  * Dynamic Storage Class :
  *     Programın çalışması sırasında (runtime) oluşturulup yok edilen nesnelerdir.
  *     new
  *     delete 
  * 
  * Thread-Local Storage Class : 
  *     Bir nesnenin depolama süresi (storage duration) thread süresidir.
  *  


* New & Delete operatörü
  * new operator - new expression
  * 
  * new Myclass - new int - new Fighter
  * 
  * Run-time esnasında işlem görür. sizeof değeri kadar bellek boyutu allocate eder.
  * 


* Smart Pointer
  * Normal pointer (T*) gibi davranır ama dinamik bellek ömrünü otomatik yönetir.
  * 
  * new/delete kullanımını user yerine yapar -->> memory leak ve dang. ptr riskini azaltır.
  * 
  * (a) std::unique_ptr: 
  *     Tek sahiplik modeli.
  *     Bir nesnenin yalnızca bir sahibi vardır.
  *     Kopyalanamaz, ancak taşınabilir (move).
  * 
  * (b) std::shared_ptr:
  *     Paylaşımlı sahiplik.
  *     Kaç tane shared_ptr aynı nesneyi gösteriyor sayılır (reference count).
  *     Son shared_ptr silinince nesne yok edilir.
  * 
  * (c) std::weak_ptr:
  *     Zayıf referans -->> shared_ptr’ı saymaz.
  *     Sahiplik yoktur, sadece gözlemci.
  *     expired() veya lock() ile kontrol edilir.
  * 
  * unique_ptr -->> Tek sahip, hafif, güvenli -->> ilk tercih
  * shared_ptr -->> Birden fazla sahiplik gerektiğinde
  * weak_ptr -->> shared_ptr ile oluşan cycle (çöp toplayıcı problemi) çözümü
  * 

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 16 - Smart Pointer & Class Static Data Members
******************************************************************************/
/******************************************************************************
** Education



* incomplete type
  * Fonksiyon bildirimlerinde kullanılabilir.
  * Örnek:

  class Onur;
Onur foo(Onur);
Onur& bar(Onur&);
Onur* baz(Onur *, int);

  * 
  * Type alias declaration
  * Örnek:

typedef Onur* OnurPtr;
typedef Onur& OnurRef;
using OnurPtr = Onur *;

  * 
  * Pointer ya da referans değişkenler tanımlanabilir.
  * 


*** MÜLAKAT: Soru/Çözüm
  * 

class Onur {
public:
    void foo(Onur *)const
    {
        // x = 6;               ///< Legaldir.
    }

    void func()
    {
        // x = 5;               ///< Legaldir.

        // this -> x;           ///< Legaldir.
    }
    
    // Onur(int i) : x(i) {}    ///< Illegaldir.

private:
    static int x;
};

  * 
***


*** MÜLAKAT:
  * Her Fighter nesnesi, hayattaki diğer Fighter nesnelerine erişebilecek.
  * 
  * 

class Fighter {
public:
    void call_fighters_for_help()
    {

    }

};

int main()
{
    Fighter f1{"Alpha"};
    Fighter f2{"Beta"};
    Fighter f3{"Charlie"};
    Fighter f4{"Delta"};
    Fighter f4{"Echo"};

    f2.call_fighters_for_help();
}

  * 
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 17 - Class Static Member Functions & Delegating Ctor (C++11)
** Friend Bildirimleri & Operator Overloading & Operator Function
******************************************************************************/
/******************************************************************************
** Education


* Class Static Member Functions
  * Name ctor:
  *     Yapıcı fonksiyonlar (constructor) statik olamaz.
  *     Ancak statik veri üyeleri genelde yapıcı içinde veya sınıf dışında başlatılır.
  *     En yaygın kullanım: oluşturulan nesne sayısını tutmak.
  * 
  * Object count:
  *     Statik üyeler genellikle nesne sayısını takip etmek için kullanılır.
  *     Statik veri üyesi, sınıfa aittir, nesnelere değil (tek bir kopya vardır).
  *     Statik fonksiyon, nesne oluşturmadan çağrılabilir.
  * 
  * Statik Veri Üyesi -->> 
  *     Tüm nesneler tarafından paylaşılan ortak değişken.
  * Statik Üye Fonksiyonu -->> 
  *     Sadece statik üyeleri kullanabilir, nesne oluşturmadan çağrılabilir.
  * Kullanım Alanı -->> 
  *     Nesne sayısını tutmak, tüm nesnelere ortak sabit/yardımcı fonksiyonları saklamak.
  * 

*** MÜLAKAT:
  * Her Fighter nesnesi, hayattaki diğer Fighter nesnelerine erişebilecek.
  * 
  * 

template <typename InIter, typename T>
InIter Find(InIter beg, InIter end, const T& val)
{
    while(beg != end)
    {
        if(*beg == val)
        {
            return beg;
        }
        ++beg;
    }
    return end;
}

class Fighter {
public:
    Fighter()
    {
        fvec_.push_back(this);
    }
    Fighter(std::string name, int age) : name_(std:move(name)), age_(age)
    {
        fvec_.push_back(this);
    }

    ~Fighter()
    {
        std::erase(fvec_, this); ///< C++20
        //or
        if (auto iter = std::find(fvec_.being(), fvec_end(), this); 
            iter !=fvec_.end())
        {
            fvec_.erase(iter);
        }
        else
        {
            std::cerr << "This pointer cannot be found in the container\n" << std::endl;
        }
    }

    Fighter(const Fighter&) = delete;               ///< Copy ctor deleted.
    Fighter& operator=(const Fighter&) = delete;    ///< Copy assignment deleted.
    void ask_for_help()
    {
        std::cout << "I'm" << name_ << "Come on!" << std::endl;
        for (auto p : fvec_)
        {
            if (p != this && p->get_age() > 20)
            {
                std::cout << p->get_name() << ' ';
            }
        }
        std::cout <" Run!" << std::endl;
    }
    std::string get_name()const
    {
        return name_;
    }
    int get_age()const
    {
        return age_;
    }

private:
    std::string name_;
    inline static std::vector<Fighter*> fvec_; ///< C++17
    int age { 0 };

};

int main()
{
    Fighter f1{"Alpha", 10};
    Fighter f2{"Beta", 20};
    Fighter f3{"Charlie", 30};
    Fighter f4{"Delta", 40};
    Fighter f4{"Echo", 50};
    
    auto p1{new Fighter{"Foxtrot", 60}};
    auto p2{new Fighter{"Golf", 70}};

    f3.ask_for_help();

    delete p1;
    delete p2;

    f1.ask_forhelp();
}

  * 
***


* Delegating ctor
  * Çoğu zaman sınıfların ctor'ları overload ediliyor.
  * Anca overload edilen ctor'ların bazen ortak bir kodu oluyor
  * DRY sorunlara sebep olur. ctor bu fonksiyonlara çağrılıyor.
  * 
  * Çoğu zaman sınıfların birden fazla overload edilmiş constructor’ı olur.
  * Bu constructor’ların içinde ortak bir başlangıç kodu bulunur.
  * 


* Friend Function
  * Bir sınıfın özel (private) ve korumalı (protected) üyelerine erişim hakkı verir.
  * Normalde dışarıdan erişilemeyen verilere, özel olarak izin verilir.
  * Hem global fonksiyon hem de başka bir sınıfın üye fonksiyonu friend olabilir.
  * 
  * Örnek:

class A {
private:
    int private_value = 42;

    friend class B;
};

class B {
public:
    void yazdir(A a) {
        cout << "A'nin private value = " << a.private_value << endl;
    }
};

  * 
  * 

* Operator Overloading
  * Bir fonksiyonu ismi ile çağırmak yerine,
  *     bir sınıf nesnesini bir operatörün operandı yapmak,
  *     bir fonksiyona yapılan çağrıya dönüştürüyor.
  * 
  * Bu mekanizma ile operatörlerin "arity" sini değiştiremeyiz.
  * arity -->> operatörün unary ya da binary olmasıdır.
  * 


* Operatörlerde binary ve unary kavramı
  * a > b -->> Operatör Binar'idir. İki operand aldığı için binary denir.
  * !x    -->> Operatör Unary'dir.
  * 
  * a > b -->> operator>(a,b)
  * !x    -->> operator!(x)n
  * 
  * member operator function
  * non-static member function
  * 
  * bool operator>(Myclass)const;
  * 

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 18 - Inserter Functions & Endl & Karsilastirma Operatorleri Overloadlari
** !(Equality Operators)
******************************************************************************/
/******************************************************************************
** Education


*** MÜLAKAT: 
  * Neden hep üye operatörü hem de global operatörü olur?
  * Sadece üye op. func. var, ne eksik kalırdı? Neyi yapamazdık?
  * 
  * Cevap:
  * Üye operatör fonksiyonları, sınıfın kendi nesnesiyle başlayan işlemleri tanımlar.
  * Global operatör fonksiyonları ise, 
  *     sol operand sınıf dışında bir tip olduğunda gerekli olur (örn. int * Vektör).
  * 
  * Eğer sadece üye fonksiyonlar olsaydı, 
  *     bu esnekliği kaybederdik ve birçok simetrik operatör (a+b ve b+a gibi)
  *     tam anlamıyla çalışmazdı.
  * 
***


* Inserter Functions
  * STL’de container'lara eleman eklemek için kullanılan yardımcı fonksiyonlardır.
  * 
  * Örnekler:
  * std::inserter(container, iterator)
  * std::back_inserter(container) → push_back kullanır.
  * std::front_inserter(container) → push_front kullanır.
  * 
  * Normal kopyalama yerine container’a elemanları doğru şekilde eklemeyi sağlar. 
  *     Özellikle std::copy veya std::transform gibi algoritmalarda çok kullanılır.
  * 
  * Örnek:

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3};
    list<int> l;

    // back_inserter ile sona ekleme
    copy(v1.begin(), v1.end(), back_inserter(l));

    // front_inserter ile başa ekleme
    copy(v1.begin(), v1.end(), front_inserter(l));

    for (int x : l) cout << x << " ";  // çıktı: 3 2 1 1 2 3
}

  * 
  * Soru: back_inserter ile inserter arasındaki fark nedir?
  * Cevap: back_inserter, container’ın push_back fonksiyonunu kullanarak hep sona ekler.
  * Inserter, belirtilen iterator konumundan ekleme yapar.
  * 
  * std::copy ile kullanırken container’ın push_back veya push_front
  *     fonksiyonlarının desteklenmesi gerekir.
  * std::set gibi sıralı container’larda inserter tercih edilir.
  * 

* Endl
  * endl = End Line
  * \n ile farkı: Satır sonu ekler ve output buffer’ı flush (boşaltır).
  * Bu yüzden \n genelde daha hızlıdır, endl ise gerçekten ekrana yazmayı garanti eder.
  * 
  * Örnek:

#include <iostream>
using namespace std;

int main() {
    cout << "Merhaba\n";     // sadece satır atlar
    cout << "Dünya" << endl; // satır atlar + buffer flush
}

  * 
  * Soru: \n ve std::endl arasındaki fark nedir?
  * Cevap: \n sadece yeni satır ekler. 
  *     std::endl ise hem yeni satır ekler hem de buffer’ı temizler.
  *     Bu yüzden endl daha maliyetlidir.
  * 
  * Performans kritik uygulamalarda (IO heavy) \n kullan,
  *     endl’ı sadece çıktının hemen ekrana yazılması gerektiğinde kullan.
  * endl aşırı kullanımda programı yavaşlatır.
  * 
  * 


* Comparison Operators Overloads
  * C++’ta operator overloading ile ==, !=, <, >, <=, >= 
  *     operatörlerini sınıflar için tanımlayabilirsin.
  * Özellikle container’lar (set, map) veya sort algoritmaları 
  *     nesneleri karşılaştırmak için bu operatörleri çağırır.
  * 
  * Örnek:

#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}

    // Eşitlik karşılaştırması
    bool operator==(const Person& other) const {
        return (name == other.name && age == other.age);
    }

    // Küçük mü karşılaştırması (yaşa göre)
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

int main() {
    Person p1("Ali", 25), p2("Ayşe", 30);

    cout << (p1 == p2) << endl; // 0
    cout << (p1 < p2) << endl;  // 1
}

  * 
  * Soru: Eğer == operatörünü overload edersen, != operatörünü de yazmalı mısın?
  * Cevap: Evet, çünkü C++ otomatik olarak != üretmez.
  *     Ama C++20 ile operator<=> kullanırsak hepsi otomatik türetilir.
  * 
  * operator< genelde std::sort için tanımlanır.
  * Mantıksal tutarlılık önemli: Eğer a == b doğruysa, a < b ve b < a yanlış olmalı.
  * C++20’de operator<=> (spaceship operator) kullanarak
  *     tüm karşılaştırma operatörlerini tek seferde yazabilirsin.
  * 


* !(Equality Operators)
  * Burada kastedilen ! işaretiyle kullanılan eşitlik operatörleri (== ve !=).
  *     == → Eşitlik kontrolü
  *     != → Eşitsizlik kontrolü
  * Bu operatörler genellikle birlikte overload edilir.
  * 
  * Örnek:

#include <iostream>
using namespace std;

class Box {
    int size;
public:
    Box(int s) : size(s) {}

    bool operator==(const Box& other) const {
        return size == other.size;
    }
    bool operator!=(const Box& other) const {
        return !(*this == other); // tekrar kullanıyoruz
    }
};

int main() {
    Box b1(10), b2(20), b3(10);

    cout << (b1 == b2) << endl; // 0
    cout << (b1 != b2) << endl; // 1
    cout << (b1 == b3) << endl; // 1
}

  * 
  * Soru: operator!= tanımlamadan sadece operator== kullanabilir miyiz?
  * Cevap: Hayır, ikisini ayrı tanımlamak gerekir (C++20’ye kadar).
  *     Ama != tanımını !(==) şeklinde implement etmek yaygın pratiktir.
  * 
  * Kod tekrarını önlemek için !=’i !(==) üzerinden tanımla.
  * Eğer == ve != mantıksal olarak çelişirse,
  *     (ör. biri true, diğeri de true dönerse) çok tehlikeli bug’lar çıkar.
  * unordered_map ve unordered_set gibi container’lar 
  *     hem == hem de hash fonksiyonuna ihtiyaç duyar.
  * 

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 19 - Increment(++) Ve Decrement(--) Overload Edilmesi & Ozel Nitelikli Operatorler
** Dereferencing/Indirection(*) Ve Arrow/Member Selection(->) Operatorleri
******************************************************************************/
/******************************************************************************
** Education


* Reference qualifiers
  * increment - decrement
  * 
  * ++x prefix increment
  * x++ postfix increment
  * 
  * --x prefix decrement
  * x-- postfix decrement
  * 
  * Örnek:

class Counter {
public:
    Counter& operator++();      prefix
    Counter operator++(int);    postfix

    Counter& operator--();      prefix
    Counter operator--(int);    postfix

};

  * 
  * 
x = y   ///< R-Value expression
x += y  ///< L-Value expression

struct S {
    void foo() & { std::cout << "lvalue nesnesi\n"; }
    void foo() && { std::cout << "rvalue nesnesi\n"; }
};

S s;
s.foo();       // lvalue -> "lvalue nesnesi"
S{}.foo();     // rvalue -> "rvalue nesnesi"

  * 
  * Atama operatörünün ürettiği değer nesneye atanan değerdir.
  * Örnek:

std::cout << (x = y = 10) << std::endl; // 10 yazdırır
std::cout << x << " " << y << std::endl; // 10 10

  * 
  * *ptr++ -->> Dizinin ilk elemanına erişilir.
  * *++ptr -->> Dizinin ikinci elemanına erişilir.
  * 

int x{123};

+x  ///< Value category -->> PR-Value
    ///< Türü nedir     -->> int
    ///< Yan etkisi     -->> Yok

  * 
  * 


* Dereferencing / Indirection (*) Operatörü
  * Operatörü pointer dereference etmek için kullanılır.
  * Operator overload ile sınıf içinden nesneye ulaşmak için de tanımlanabilir.
  * 
  * Örnek:

class PtrWrapper {
    int value;
public:
    PtrWrapper(int v) : value(v) {}

    int& operator*() {   // Dereference overload
        return value;
    }
};

int main() {
    PtrWrapper pw(42);
    std::cout << *pw << std::endl; // 42
}

  * 
  * 


* Arrow / Member Selection (->) Operatörü
  * -> operatörü pointer üzerinden nesne üyesine erişmek için kullanılır.
  * Overload edilerek akıllı pointer benzeri davranış sağlanabilir.
  * 
  * Örnek:

struct Obj {
    void hello() { std::cout << "Merhaba\n"; }
};

class SmartPtr {
    Obj* p;
public:
    SmartPtr(Obj* ptr) : p(ptr) {}

    Obj* operator->() {   // Arrow overload
        return p;
    }
};

int main() {
    Obj o;
    SmartPtr sp(&o);
    sp->hello(); // "Merhaba"
}

  * 
  * 


*** MÜLAKAT:
  * 

void bar(int&)
{
    std::cout << "1";
}

void bar(int&&)
{
    std::cout << "2";
}

void foo(int&& x)
{
    bar(x);
}

int main()
{
    //foo(5); ///< Syntax error yok. Cevap: 1'dir.
}

  * 
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 20 - Template Giriş & Function Call Overload & Tür Dönüştürme Operatorleri
******************************************************************************/
/******************************************************************************
** Education


* Introduction to Template
  * Template (şablon), C++’ta türden bağımsız programlama yapılmasını sağlar.
  * Aynı işlevi veya sınıfı farklı veri tipleri için tekrar tekrar yazmak yerine,
  *     template yapısı kullanılarak tek bir tanım üzerinden farklı türlerle çalışılabilir.
  * Hem function template hem de class template kullanılabilir.
  * 
  * Örnek:

// Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Class Template
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

int main() {
    std::cout << add<int>(3, 4) << std::endl;      // 7
    std::cout << add<double>(2.5, 4.2) << std::endl; // 6.7

    Box<std::string> b("Hello Templates");
    std::cout << b.getValue() << std::endl;        // Hello Templates
}

  * 
  * 


* Function Call Overload
  * operator() fonksiyon çağrı operatörüdür.
  * Bu operatör overload edilerek sınıf nesneleri fonksiyon gibi
  *     çağrılabilir hale getirilebilir.
  * Özellikle functor (function object) tanımlamak için kullanılır.
  * 
  * Örnek:

class Multiplier {
private:
    int factor;

public:
    Multiplier(int f) : factor(f) {}

    int operator()(int x) {   // Function call overload
        return x * factor;
    }
};

int main() {
    Multiplier times3(3);
    std::cout << times3(10) << std::endl; // 30

    Multiplier times5(5);
    std::cout << times5(4) << std::endl;  // 20
}

  * 
  * 


* Type Conversion Operator
  * User Define Conversion (UDC)
  *     Conversion ctor : Sınıfın int türünden ctor varsa,
  *         o int türünden ya da int'e dönüştürülebilecek bir değerin,
  *         sınıf türüne dönüştürmesini sağlıyor.
  * 
  *     operator T : 
  * 
  * Standard Conversion -->> User define conversion
  * User define conversion -->> Standard Conversion
  * 
  * Örnek:

class A {

};

class B {
public:
    B();
    B(A);

};

class C {
public:
    C();
    C(B);

};

int main()
{
    C cx;
    //B bx;
    A ax;

    cx = ax;    ///< Invalid.
    //bx = ax;  ///< Valid.
}

  * 
  * 


*** MÜLAKAT:
  * Soru çözümünü yapınız.

class Myclass {
public:
    operator bool()const
    {
        return true;
    }

};

int main()
{
    Myclass m1, m2;
    auto x = m1 + m2;   ///< auto x = m1.operator bool() + m2.operator bool();

    std::cout << "x = " << x << '\n;
}

  * Cevap : 2'dir. x'in türü int'tir.
***


*** MÜLAKAT:
  * Soru çözümünü yapınız.

class Myclass {
public:
    operator bool()const
    {
        return true;
    }

};

int main()
{
    double x{};
    
    Myclass m;

    x = m;  ///< Geçerlidir.
}

  * 
  *  Cevap : 2'dir. x'in türü int'tir.
  * Sınıfların operator bool func'ları her zaman explicit olarak bildirilir.
  * 
***

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 21 - Extern C Bildirimi & Composition (Containment) & Reference Qualifiers
******************************************************************************
** Education


* Extern C notification
  * Derleyici, fonksiyon isimlerini name mangling (isim bozma) ile farklı şekilde saklar 
  *     (aynı isimli fonksiyonların overload edilmesini sağlamak için).
  * C dilinde ise name mangling yoktur.
  * Eğer bir C kütüphanesini C++ içinde kullanmak istersek,
  *     fonksiyon bildirimlerini extern "C" ile işaretlememiz gerekir.
  *     Böylece C++ derleyicisine “bu fonksiyon C stilinde tanımlıdır,
  *     isim bozma yapma” demiş oluruz.
  * 
  * Örnek:

#include <stdio.h>
void c_function() {
    printf("Hello from C function!\n");
}

#ifdef __cplusplus
extern "C" {
#endif

void c_function();

#ifdef __cplusplus
}
#endif

#include <iostream>
#include "mathlib.h"

int main() {
    c_function(); // C fonksiyonunu C++ içinden çağırıyoruz
    return 0;
}

  * 
  * extern "C" sadece bağlayıcı (linkage) bilgisini değiştirir, kodun derlenmesini etkilemez.
  * Genellikle C header dosyalarını C++ projelerine dahil ederken kullanılır.
  * 


* Composition (Containment)
  * Composition (Containment): Bir sınıfın başka bir sınıfı üyeleri içinde barındırmasıdır.
  *     Yani “has-a” (sahiplik) ilişkisini ifade eder.
  * Örnek: Bir Car sınıfının içinde Engine bulunur. 
  *     Bu durumda araba motoru içerir, bu inheritance (kalıtım) değildir.
  * 
  * Örnek:

#include <iostream>
class Engine {
public:
    void start() { std::cout << "Engine started\n"; }
};

class Car {
    Engine engine; // Composition
public:
    void drive() {
        engine.start();
        std::cout << "Car is moving\n";
    }
};

int main() {
    Car car;
    car.drive();
}

Inheritance (is-a): Car bir Vehicle’dır.

Composition (has-a): Car bir Engine içerir.

  * 
  *   * “Composition ve Inheritance arasında tercih yaparken neye dikkat edersin?”
  * Cevap : “Genellikle ‘is-a’ ilişkisi varsa inheritance,
  *     ‘has-a’ ilişkisi varsa composition tercih edilir.
  *     Ayrıca composition daha gevşek bağlılık sağlar,
  *     inheritance daha sıkı bağlılık yaratır.”
  * 


* Reference Qualifiers
  * C++11 ile gelen & (lvalue reference) ve && (rvalue reference) qualifier’ları,
  *     üye fonksiyonların hangi tür nesneler üzerinde çağrılabileceğini belirler.
  * Amaç : Lvalue ve rvalue nesneler için farklı davranış tanımlamaktır.
  * 
  * Örnek:

#include <iostream>
class Data {
public:
    void show() & {  // sadece lvalue nesnelerde çağrılır
        std::cout << "Called on lvalue\n";
    }
    void show() && { // sadece rvalue nesnelerde çağrılır
        std::cout << "Called on rvalue\n";
    }
};

int main() {
    Data d;
    d.show();         // lvalue -->> "Called on lvalue"
    Data().show();    // rvalue -->> "Called on rvalue"
}

  * 
  * Lvalue qualifier (&) -->> sadece isimli, bellekte var olan nesnelerde çalışır.
  * Rvalue qualifier (&&) -->> geçici nesneler üzerinde çalışır.
  * Modern C++’ta move semantics ve perfect forwarding ile birlikte önem kazanmıştır.
  * 

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 22 - Namespaces (İsim Alanları) & Unnamed Namespace
******************************************************************************
** Education


* Namespace
  * Farklı dosya ve sınıflardan gelen global isimlerin birbirine karışmamasını sağlar.
  * Namespace, ad çakışmalarını önlemek ve kodun düzenli olmasını sağlamak için kullanılan bir yapıdır.
  * Büyük projelerde farklı kütüphanelerden gelen fonksiyon veya sınıf isimlerinin çakışmasını önler.
  * namespace anahtar kelimesi ile tanımlanır.
  * 
  * Örnek:

#include <iostream>

// namespace tanımı
namespace Matematik {
    int topla(int a, int b) {
        return a + b;
    }
    int carp(int a, int b) {
        return a * b;
    }
}

int main() {
    std::cout << "Toplam: " << Matematik::topla(5, 3) << std::endl; // 8
    std::cout << "Çarpım: " << Matematik::carp(5, 3) << std::endl;   // 15
    return 0;
}

  * 
  * Namespace içindeki öğelere erişim için :: (scope resolution operator) kullanılır.
  * Namespace’ler iç içe tanımlanabilir.
  * 


* Using Declaration (using)
  * using keyword’ü, uzun namespace isimlerini sürekli yazmamak için kullanılır.
  * Bir namespace’i tamamen veya sadece belirli bir öğeyi kullanılabilir hale getirir.
  * 
  * Örnek:

#include <iostream>

namespace Matematik {
    int topla(int a, int b) { return a + b; }
    int carp(int a, int b) { return a * b; }
}

using Matematik::topla; // Sadece topla fonksiyonunu erişilebilir yapar

int main() {
    std::cout << "Toplam: " << topla(4, 6) << std::endl; // Matematik::topla yerine sadece topla
    // std::cout << carp(4, 6); // HATA: carp fonksiyonu görünür değil
    return 0;
}

  * 
  * 


* Unnamed namespace
  * Static değişken ve fonksiyonların yaptığı işi modern C++’ta yapar:
  *     Sadece tanımlandığı dosyada görünür (file-scope visibility).
  * Amaç: Global namespace’e sızmayı önlemek, dosya içi gizlilik sağlamak.
  * 
  * Örnek:

#include <iostream>

namespace {
    int gizliSayi = 42;

    void gizliFonksiyon() {
        std::cout << "Bu fonksiyon sadece bu dosyada görünür!" << std::endl;
    }
}

int main() {
    std::cout << "Gizli Sayı: " << gizliSayi << std::endl;
    gizliFonksiyon();
    return 0;
}

  * 
  * Unnamed namespace’teki öğeler sadece tanımlandığı dosyada erişilebilir.
  * Static keyword’ü ile benzer işlev görür, ancak unnamed namespace modern C++ yaklaşımıdır.
  * 

*** MÜLAKAT:
  * Soru: Namespace neden kullanılır?
  * Cevap: Farklı kütüphanelerde veya modüllerde aynı isimdeki
  *     fonksiyon/sınıf/degiskenlerin çakışmasını önlemek ve kodu organize etmek
  * 
  * Soru: using namespace ile using arasındaki fark nedir?
  * Cevap:
  * using namespace X; -->> namespace içindeki tüm öğeleri görünür yapar.
  * using X::Y; -->> sadece Y öğesini görünür yapar, isim çakışmasını önler.
  * 
  * Soru: Unnamed namespace ne zaman kullanılır?
  * Cevap: Dosya düzeyinde öğeleri gizlemek ve global namespace kirliliğini önlemek.
  *     Static yerine modern C++’ta önerilen yöntemdir.
  * 
  * using namespace std; kullanımını sorabilirler -->> küçük projelerde kabul edilebilir, 
  *     Büyük projelerde önerilmez.
  * Namespace iç içe tanımlanabilir ve isim çakışmaları nasıl çözülür sorulabilir.
  * Unnamed namespace’in ve static keyword’ünün farkını bilmek önemlidir.
  * Kod örneği üzerinden namespace ve using kullanımını sorabilirler;
  *     Basit ama etkili örnekler hazırlayın.
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 23 - Nested Types & Pimpl Idiom (Handle-Body Idiom, Cheshire Cat, Compiler Firewall, Opaque Pointer)
** Inheritance (Kalıtım)
******************************************************************************
** Education


* Nested Types
  * Bir sınıfın içinde tanımlanan başka bir sınıf, struct veya enum’dur.
  * Amaç: Bir türün sadece kapsayıcı sınıf bağlamında anlamlı olduğunu göstermek
  *     ve kodu organize etmek.
  * 
  * Örnek:

#include <iostream>

class OuterClass {
public:
    class InnerClass {  // nested type
    public:
        void showMessage() { std::cout << "Hello, I am the inner class!" << std::endl; }
    };

    void run() {
        InnerClass inner;  
        inner.showMessage();
    }
};

int main() {
    OuterClass::InnerClass inner2; // Access from outside
    inner2.showMessage();

    OuterClass outer;
    outer.run();
    return 0;
}

  * 
  * Nested type dışarıdan DışSınıf::İçSınıf ile erişilir.
  * Sadece kapsayıcı sınıf bağlamında anlamlı türleri saklamak için idealdir.
  * 


* Pimpl Idiom
  * Bir sınıfın uygulama detaylarını gizlemek için kullanılır
  *     (Encapsulation + Compile-time optimization).
  * Sınıfın iç detayları başlık dosyasından gizlenir,
  *     böylece derleme süreleri kısalır ve bağımlılık azalır.
  * 
  * Örnek:

#include <iostream>
#include <memory>

// Interface class
class Hidden {
public:
    Hidden();
    ~Hidden();
    void showMessage();
private:
    class Impl;                 // Pimpl: hidden implementation
    std::unique_ptr<Impl> pImpl; 
};

// Implementation
class Hidden::Impl {
public:
    void showMessage() { std::cout << "Hello from Pimpl!" << std::endl; }
};

Hidden::Hidden() : pImpl(std::make_unique<Impl>()) {}
Hidden::~Hidden() = default;

void Hidden::showMessage() { pImpl->showMessage(); }

int main() {
    Hidden h;
    h.showMessage();
    return 0;
}

  * 
  * Header dosyasındaki implementasyon detayları gizlenir -->> bağımlılık azalır.
  * Hafıza yönetimi için unique_ptr veya shared_ptr kullanmak yaygındır.
  * Modern C++’ta std::unique_ptr ile birlikte tercih edilir.
  * 


* Inheritance
  * Inheritance, bir sınıfın başka bir sınıftan özellikleri ve 
  *     Fonksiyonları devralmasını sağlar.
  * C++’ta 3 tür kalıtım vardır: public, protected, private.
  * 
  * Örnek:

#include <iostream>

class Animal {
public:
    void makeSound() { std::cout << "Animal sound" << std::endl; }
};

class Cat : public Animal { // public inheritance
public:
    void meow() { std::cout << "Meow!" << std::endl; }
};

int main() {
    Cat c;
    c.makeSound();  // Calls Animal::makeSound
    c.meow();       // Calls Cat::meow
    return 0;
}

///< With virtual function and destructor:
class Animal {
public:
    virtual void makeSound() { std::cout << "Animal sound" << std::endl; }
    virtual ~Animal() = default;
};

  * 
  * public inheritance -->> base class’ın public üyeleri derived class’ta public kalır.
  * protected inheritance -->> base public/protected üyeler derived’da protected olur.
  * private inheritance -->> base public/protected üyeler derived’da private olur.
  * Polymorphism için virtual functions ve virtual destructor önemli.
  * 

*** MÜLAKAT:
  * 
  * Soru: Nested type ne zaman kullanılır?
  * Cevap: Bir tür yalnızca kapsayıcı sınıf bağlamında anlamlıysa veya
  *     kapsayıcı sınıfın bir parçası olarak gruplanması gerekiyorsa.
  * 
  * Soru: Pimpl idiom ne işe yarar?
  * Cevap: Implementasyon detaylarını header’dan gizleyerek bağımlılıkları azaltır
  *     ve derleme sürelerini kısaltır.
  * 
  * Soru: Public, protected ve private inheritance arasındaki fark nedir?
  * Cevap: Base class üyelerinin derived class’ta erişim seviyesini değiştirir.
  * 
  * Public -->> public kalır
  * Protected -->> protected olur
  * Private -->> private olur
  * 
  * Soru: Virtual destructor neden önemlidir?
  * Cevap: Derived class nesnesi base pointer ile silindiğinde,
  *     derived destructor çağrılmasını sağlar ve bellek sızıntısını önler.
  * 
  * 
  * Nested type kullanımının avantajlarını ve sınırlamalarını anlatabilmek.
  * Pimpl idiom ile #include bağımlılığını azaltmayı ve,
  *     modern C++’ta pointer yönetimini bilmek.
  * Kalıtım türleri ve polymorphism sorulabilir.
  * Virtual destructor ve override keyword’ünü bilmek, örnekle göstermek.
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 24 - Inheritance Devam & Inheritance And Name Look-Up
******************************************************************************
** Education


*** MÜLAKAT:
  * Inheritance
  * 
  * Taban ve türetilmiş sınıfta bildirilen aynı isimli fonk'lar overload değildir.
  * 
***

* Inheritance and Name look-up
  * 
  * Örnek:

class Base {
public:
    void foo();

};

class Der : public Base {
public:
    void foo(int);

};

int main()
{
    Der myder;

    //myder.foo();      ///< Legal mi? -->> Illegaldir. 
                        ///<                Param olan değişkene arg. gönderilmedi

    //myder.foo(12);    ///< myder nesnesiyle taban fonk. foo olan fonk. çağrı yapılabilir mi?
    //myder.Base::foo();///< Evet!

    //myder.foo(3.4);   ///< foo fonk'ları double ve int param almıştır.
                        ///< Bu durumda func. overloading durumu değildir.
    
    // İsim nitelenmeden kullanıldığı için,
    // Blokta aranır -->> class X : public Base scope'ta -->> Base scope'ta -->> namespace
}

  * 
  * 


*** MÜLAKAT:
  * Türemiş sınıfın bir üye fonksiyonu içinde bir isim nitelenmeden kullanılırsa,
  * 
  * İsim önce blokta
  *     sonra kapsayan blokta
  *         sonra türemiş sınıf tanımında
  *             sonra taban sınıf tanımında
  *                 sonra namespace'de aranır.
  * 
***


* Run-Time Polymorphism
  * Car sınıfı kalıtım olarak elde edildi.
  * Özetle, her "Audi" ve "Volvo" bir "Car"dır.
  * 
  * Örnek:

class Car {
public:
    virtual void start()        ///< virtual nesnesi ile yazınca Car::start olmaz.
    {
        std::cout << "Car::start\n";
    }
};

class Audi : public Car {
public:
    void start()
    {
        std::cout << "Audi::start\n";
    }

};

class Volvo : public Car {
public:
    void start()
    {
        std::cout << "Volvo::start\n";
    }

};

void car_game(Car* ptr)
{
    ptr->start();
}

int main()
{
    Audio a;
    Volvo v;

    car_game(&a);
    car_game(&v);
}

  * 
  * static/early binding : Func overloading. 
  *                        10 func olsa hangisi çağrıldığı compiler-time'da anlaşılır.
  * 
  * dynamic/late binding : Run-time'da anlaşılır. RND örnek verilebilir.
  * 

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 25 - Virtual (Virtual Dispatch, Runtime Polymorphism)
******************************************************************************
** Education


* Virtual Function
  * Bir base (taban) class içinde virtual keyword ile tanımlanmış fonksiyondur.
  * Amaç: runtime polymorphism (çalışma zamanı çok biçimlilik) sağlamaktır.
  * Yani, bir base class pointer/reference ile işaret edilen derived class
  *     nesnesinin override edilmiş metodunu çalıştırabilmektir.
  * 


* Virtual Dispatch (V-Table Mekanizması)
  * C++ derleyicileri, her virtual fonksiyon için bir vtable
  *     (virtual function table) oluşturur.
  * Her nesne, vtable’a işaret eden bir pointer (vptr) taşır.
  * Çağrı yapılınca hangi fonksiyonun çalışacağı çalışma zamanında (runtime) belirlenir.
  * Bu yüzden buna dynamic dispatch denir.
  * 


* Kullanım Senaryosu
  * Polymorphism: Base class arayüzü kullanarak farklı türevlerin davranışını çalıştırmak.
  * 
  * Design Patterns: Strategy, State, Visitor gibi desenlerin çoğu
  *     virtual dispatch üzerine kuruludur.
  * 
  * OOP Hierarchies: Ortak arayüz + özelleşmiş davranış.
  * 
  * Örnek:

#include <iostream>
#include <memory>
using namespace std;

class Animal {
public:
    virtual void speak() { // Virtual function
        cout << "Animal makes a sound." << endl;
    }
    virtual ~Animal() { // Her zaman virtual destructor kullan
        cout << "Animal destroyed" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override { // Override edilmesi önerilir
        cout << "Woof! Woof!" << endl;
    }
    ~Dog() {
        cout << "Dog destroyed" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
    ~Cat() {
        cout << "Cat destroyed" << endl;
    }
};

int main() {
    // Base pointer -> Derived object
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak(); // Runtime’da Dog::speak() çağrılır
    a2->speak(); // Runtime’da Cat::speak() çağrılır

    delete a1; // Virtual destructor sayesinde Dog + Animal yok edilir
    delete a2;

    // Modern yaklaşım (smart pointer)
    unique_ptr<Animal> a3 = make_unique<Dog>();
    a3->speak();

    return 0;
}

Cevap:
    Woof! Woof!
    Meow!
    Dog destroyed
    Animal destroyed
    Cat destroyed
    Animal destroyed
    Woof! Woof!
    Dog destroyed
    Animal destroyed

  * 
  * 

  
*** MÜLAKAT:
  * C++’ta neden destructor’lar genellikle virtual yapılır?
  * 
  * Eğer bir base class pointer ile derived class nesnesi oluşturup delete edersek,
  *     base class destructor virtual değilse, sadece base destructor çağrılır,
  *     derived destructor çağrılmaz -->> memory leak ve kaynak sızıntısı olur.
  * 

class Base {
public:
    ~Base() { cout << "Base destroyed"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destroyed"; }
};

int main() {
    Base* b = new Derived();
    delete b; // Derived destructor çağrılmaz -->> tehlikeli!
}

  * 
  * 
***


*** MÜLAKAT:
  * Virtual function ile function overloading arasındaki fark nedir?
  * Virtual function = runtime polymorphism, overload = compile-time polymorphism.
  * 
  * Pure virtual function nedir?
  * virtual void foo() = 0; -->> abstract class oluşturur.
  * 
  * Virtual table (vtable) nedir, nasıl çalışır?
  * Derleyici tarafından oluşturulan tablo;
  *     hangi fonksiyonun çalıştırılacağını runtime’da çözer.
  * 
***


*** MÜLAKAT:
  * Virtual destructor kullan: Base class’ların destructor’unu her zaman virtual yap.
  * 
  * override keyword: Derived class’ta virtual fonksiyonları override ederken override kullan -->> yazım hatalarını yakalar.
  * 
  * Base class’ta gereksiz virtual yapma: Sadece polymorphic davranış gerekiyorsa virtual ekle. 
  *     Gereksiz virtual -->> ek maliyet (vtable + indirection).
  * 
  * Final keyword: Eğer derived class’ta bir fonksiyonun daha override edilmesini istemiyorsan final kullan:
  * 

void speak() override final;

  * 
  * Interface için pure virtual: Eğer sınıf sadece arayüz ise -->> =0 ile pure virtual yap.
  * 
  * Smart pointer tercih et: Manual new/delete yerine unique_ptr veya shared_ptr kullan.
  * 
  * Object slicing’e dikkat et: Base class by-value kopyalanırsa derived özellikleri kaybolur -->> her zaman reference veya pointer kullan.
  * 
***


* Dynamic Binding / Late Binding
  * Bir taban sınıfın fonksiyonları
  * 
  * 1. Türemiş sınıflara hem bir interface hem de bir implementasyon veren fonk'lar
  * Airplane
  *     takeoff
  * 
  * 2. Türemiş sınıflara hem bir interface hem de bir default implementasyon veren fonk'lar
  *     fly
  * 
  * 3. Türemiş sınıflara yalnızca bir interface veren implementasyon vermeyen fonk'lar
  *     land
  * 
  * override (function overriding)
  * 
  * Bir sınıfın en az 2. kategoride bir fonksiyonu varsa,
  *     Böyle sınıflara polymorphic (çok biçimli)
  * 
  * Bir sınıfın en az 3. kategoride en az bir fonksiyonu varsa,
  *     Böyle sınıflara abstract class (soyut sınıf)
  * 
  * Örnek:

class Airplane {
public:
    void takeoff();
    virtual void fly();         ///< Virtual Function - Sanal fonksiyon
    virtual void land() = 0;    ///< Pure virtual function - Saf sanal fonksiyon

};

class Airbus : public Airplane { };

int main()
{
    Airplane a;
}

  * 
  * 
 

* Virtual dispatch (Sanal gönderim)
  * Eğer bir fonksiyon çağırısı
  * taban sınıf türünden bir nesne ile değil
  * taban sınıf türünden bir pointer değişken ya da
  * taban sınıf türünden bir referans değişken ile yapılmasıdır.
  * 

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 26 - Covariance (Variant Return Type) & RTTI (Runtime Type Information) (Giriş)
** NVI (Non-Virtual Interface İdyomu) (Giriş) & Final (Contextual Keyword)
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 27 - Private Inheritance & Protected Kalıtım & Multiple Inheritance
** RTTI (Runtime Type Information)
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 28 - RTTI Devam (Runtime Type Information) & Typeid & Std::String & Dinamik Array
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 29 - String Devam & Initializer_List Minik Giriş & String Devam
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 30 - String Devam
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 31 - Exception Handling
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 32 - Exception Guarantee(S)
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 33 - Noexcept & Generic Programming (Templates) in C++
******************************************************************************
** Education


* noexcept
  * noexcept, C++11 ile gelen bir keyword’dür.
  * Fonksiyonun exception throw olmadığını garanti eder.
  * Derleyiciye ve optimize ediciye bilgi verir,
  *     exception güvenli kod yazmayı kolaylaştırır.
  * Örnek:
  * 

void f() noexcept;          // exception non-throw
void g() noexcept(true);    // f ile aynı
void h() noexcept(false);   // exception throw

  * 
  * 
  * Performans optimizasyonu: std::vector gibi container’lar
  *     noexcept constructor/destructor ile daha hızlı çalışır.
  * 
  * Exception safety: Exception garantisi vermek istediğimiz fonksiyonlarda.
  * 
  * Move semantics: Move constructor’larda noexcept kullanılması önerilir.
  * 
  * no-throw garantisi vermeme durumunda hatalı argümanlar vardır.
  * Zorlayıcı sebep yoksa no-throw garantisi vermelidir.
  *     move ctor
  *     swap
  *     memory deallocation
  * 


* Generic Programming & Templates
  * Template parametrs -->> <>
  *     Type parameter -->> Bu isim bir türe karşılık geliyor.
  *     Non-type parameter -->> Bu isim bir sabite karşılık geliyor.
  *     template parameter
  * 

template <class T>
template <typename T>

template <typename T, typename U>   ///< Birden fazla yazılma durumu
template <typename T> <<-->> <typename> ///< Aynı ifadedir.

  * 
  * 
  * Örnek:
  * 

template <std::size_t n>
class Bitset {
};
int main() { Bitset<32> } ///< 32 bitlik olduğunubelirtir.

  * 
  * 
  * Örnek:
  * 

template <typename T, int N>
void func(T(&)[N])
{

}

  * 
  * 
  * Örnek:
  * 

template <typename T, T x> ///< T: type parameter.
                           ///< x: non-type parameter.
class Myclass {
};

  * 
  * 
  * Örnek:
  * 

template <typename T, int N>
void func(T x)
{
     
}

  * 
  * 

* Generic Programming & Templates
  * Generic Programming, veri tipinden bağımsız algoritma yazma yaklaşımıdır.
  * Templates, C++’ta generic programlamayı sağlayan yapıdır.
  * 
  * Örnek:
  * 

///< Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

///< Class Template
template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T get() { return value; }
};

  * 
  * 
  * Compile-time’da tür belirlenir -->> type safety sağlar.
  * Kod tekrarı azalır.
  * typename veya class keyword’ü template parametresi için kullanılabilir.
  * 
  * 
  * Template specialization: Belirli tipler için özelleştirme.
  * 
  * Concepts (C++20): Type constraints, compile-time kontrol.
  * 
  * Variadic templates: İstenilen sayıda template parametresi.
  * 
  * 


* Örnekler:
  * noexcept
  * 

#include <iostream>
#include <vector>
using namespace std;

void mayThrow() { throw runtime_error("Error"); }
void noThrow() noexcept { cout << "No exception!\n"; }

int main() {
    try {
        noThrow();   // güvenli, exception yok
        mayThrow();  // exception throw
    } catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}

  * 
  * 
  * Function Template
  * 

  #include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maxValue(10, 20) << endl;       // int
    cout << maxValue(3.5, 2.7) << endl;     // double
    return 0;
}

  * 
  * 
  * Class Template
  * 

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T data[10];
    int top = -1;
public:
    void push(T val) { data[++top] = val; }
    T pop() { return data[top--]; }
};

int main() {
    Stack<int> s1;
    s1.push(10); s1.push(20);
    cout << s1.pop() << endl;

    Stack<string> s2;
    s2.push("Hello");
    cout << s2.pop() << endl;

    return 0;
}

  * 
  * 


*** MÜLAKAT:
  * Soru 1: Move constructor’da noexcept neden önemlidir?
  * 
  * std::vector gibi container’lar elemanları taşırken move constructor çağırır.
  * Move constructor noexcept değilse, 
  * vector copy constructor kullanır -->> performans kaybı.
  * 
  * Özet: noexcept move semantics ile performansı artırır.
  * 
  * 
  * Soru 2: Template ile normal fonksiyon arasındaki fark nedir?
  * 
  * Normal fonksiyon: Sabit tipte, compile-time’da belirli.
  * Template: Generic, compile-time’da tür türetilir ve type safe.
  * 
***

*** MÜLAKAT:
  * noexcept
  * Move constructor & move assignment operator’ı noexcept yap.
  * Fonksiyonun exception throw olmayacağından eminsen noexcept kullan -->> optimizasyon.
  * Fonksiyon noexcept(false) veya throw -->> default değil.
  * 
  * 
  * Templates
  * Gereksiz template’ten kaçın -->> compile-time büyüme + uzun hata mesajları.
  * typename vs class: Fonksiyon ve sınıf template’lerinde aynı anlam.
  * Modern C++20 Concepts kullan -->> type constraints ile derleme hatalarını azalt.
  * Template specialization ile tip özelleştirmesi yap.
  * Variadic templates ile fonksiyon/constructor’ları esnek hale getir.
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 34 - Function Templates
******************************************************************************
** Education


* Template Parameters
  * Template type parameter
  * Template non-type parameter
  * Template template parameter
  * 
  * 


* Function Templates
  * Template argument deduction
  *     Hangi template argümanlarını kullanacağını, func bakarak anlamaktadır.
  * 
  * Örnek:
  * 

template <typename T>
void foo(T)
{
    // TODO: Do Sth
}
int main()
{
    foo(1.9);       ///< T için yapılan çıkarım: double

    const int ival = 4;
    foo(ival);      ///< T için yapılan çıkarım: int (const düşer)
}

  * 
  * 
  * Öyle bir fonksiyon oluşturun ki, sadece belirli bir türden argüman kabul etsin
  * 

template <typename T>
void func(T) = delete;

void func(int);

int main()
{
    func(12);
}

  * 
  * 

* Function Templates
  * Farklı veri tipleriyle çalışan genel (generic) fonksiyonlar yazmamızı sağlar.
  * Aynı mantığı int, double, string gibi farklı tipler için
  *     tekrar tekrar yazmak yerine tek bir şablon tanımlarız.
  * Derleyici, fonksiyon çağrıldığında doğru versiyonu compile time üretir.
  * 
  * Örnek:
  * 

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "int toplama: " << add(5, 10) << std::endl;           // int
    std::cout << "double toplama: " << add(3.5, 2.1) << std::endl;     // double
    std::cout << "char toplama: " << add('A', (char)1) << std::endl;   // char (ASCII matematik)
    return 0;
}

  * 
  * 
  * Örnek:
  * 

///< auto + decltype -->> dönüş tipini otomatik çıkarır.
template <typename T1, typename T2>
auto multiply(T1 a, T2 b) -> decltype(a * b) {
    return a * b;
}

int main() {
    std::cout << multiply(3, 4.5) << std::endl; // int * double = double
    return 0;
}

  * 
  * 
  * Örnek:
  * 

///< Fonksiyon Şablonu Özelleştirme (Specialization)
template <typename T>
T printTwice(T value) {
    return value + value;
}

// std::string için özel versiyon
template <>
std::string printTwice<std::string>(std::string value) {
    return value + " " + value;
}

int main() {
    std::cout << printTwice(5) << std::endl;                  // 10
    std::cout << printTwice(2.5) << std::endl;                // 5.0
    std::cout << printTwice(std::string("Merhaba")) << std::endl; // "Merhaba Merhaba"
    return 0;
}

  * 
  * 


*** MÜLAKAT:
  * Soru: Fonksiyon şablonları neden kullanılır?
  * Cevap: 
  * Farklı tipler için aynı mantığı tekrar yazmak yerine tek bir genel fonksiyon tanımlamak.
  * 
  * Soru: Fonksiyon aşırı yükleme (overloading) ile şablonlar arasındaki fark nedir?
  * Cevap:
  * Overloading -->> her tip için ayrı ayrı fonksiyon tanımlanır.
  * Template -->> derleyici gerekli versiyonu otomatik üretir.
  * 
  * Soru: Şablonlar ne zaman üretilir (instantiate edilir)?
  * Cevap: Yalnızca şablon çağrıldığında, yani kullanıldığında.
  * 
  * Soru: Makrolara göre avantajı nedir?
  * Cevap: Şablonlar tip güvenlidir, derleme zamanında kontrol yapılır;
  *     makrolar sadece metin değiştirme yapar.
  * 
  * 
  * Tip çıkarımı (type deduction) -->> derleyici tipi otomatik bulur.
  * 
  * Compile-time çalıştığını mutlaka vurgula.
  * 
  * specialization (özelleştirme) ve SFINAE (ileri seviye) bilmek avantaj sağlar.
  * 
  * Fazla şablon kullanımı binary bloat (derlenmiş dosya büyüklüğü) sorunu yaratabilir
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 35 - Class Templates (Sınıf Şablonu) & Explicit Specialization (Full Specialization)
******************************************************************************
** Education


* Class Templates
  * 
  * Örnek:
  * 

///< Sınıf şablonu değildir.
class Myclass {
public:

    ///< Function şablonudur.
    ///< Sınıfın üye fonksiyonudur.
    ///< Member template'dir.
    template<typename T>
    void func(T x); // bool operator()(T)const;

};

int main()
{
    Myclass m;
    m.func(1.4);    ///< OK
    m.func(1);      ///< OK
}

  * 
  *  


* std::pair
  * İki farklı türden olacak ögeyi tek bir biçimde paketliyor.
  * 
  * Örnek:
  * 

#include <utility>

template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

//Pair<int, double>


std::pair<int, double> foo();

int main()
{
    pair<double, double> pd{1.2, 3,4};
    pair<int, int> pi{12, 34};

    pdf = pi; ///< syntax hatası olması lazım.
}

int main()
{
    std::pair p1{4, 1.2}; ///< CTAD: Class template deduction.
}

  * 
  * 


* Non-type parameter
  * Tam sayı türleri
  * Enum türleri
  * object pointer/referans türleri
  * function pointer
  * member function pointer
  * 
  * 


* Class Templates
  * Bir sınıfın farklı veri tipleriyle çalışabilmesi için tanımlanır.
  * 
  * Fonksiyon şablonuna benzer ama bir sınıfın tüm yapısını generic hale getirir.
  * 
  * Derleyici, sınıfı kullanıldığı tipler için ayrı ayrı oluşturur.
  * 
  * Örnek:
  * 

///< Box<int> ve Box<std::string> derleme sırasında ayrı sınıflar gibi üretilir.

// Generic class template
template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() const { return value; }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> strBox("Hello Templates");

    std::cout << intBox.getValue() << std::endl;   // 42
    std::cout << strBox.getValue() << std::endl;   // Hello Templates
    return 0;
}

  * 
  * 


* Class Template with Multiple Parameters
  * 
  * Örnek:
  * 

  template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void print() {
        std::cout << "First: " << first << ", Second: " << second << std::endl;
    }
};

int main() {
    Pair<int, double> p1(10, 3.14);
    Pair<std::string, int> p2("Age", 25);

    p1.print(); // First: 10, Second: 3.14
    p2.print(); // First: Age, Second: 25
    return 0;
}

  * 
  * 


* Explicit Specialization (Tam Özelleştirme)
  * Bazen genel şablon yeterli olmaz. Belirli bir tip için farklı davranış istenir.
  * 
  * İşte burada explicit specialization kullanılır.
  * 
  * Örnek:
  * 

///< Burada Printer<int> genel şablonu kullanır.
///< Printer<std::string> içinse özel davranış uygulanır.

// General template
template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "General: " << value << std::endl;
    }
};

// Explicit specialization for std::string
template <>
class Printer<std::string> {
public:
    void print(std::string value) {
        std::cout << "String specialization: " << value << std::endl;
    }
};

int main() {
    Printer<int> p1;
    Printer<std::string> p2;

    p1.print(100);             // General: 100
    p2.print("Hello World");   // String specialization: Hello World
    return 0;
}

  * 
  * 


* Partial Specialization
  * Partial specialization yalnızca sınıflar için geçerlidir.
  * 
  * Bir kısmı generic kalırken, belirli tiplere özel davranış tanımlanır.
  * 
  * Örnek:
  * 

template <typename T1, typename T2>
class Pair {
public:
    void show() { std::cout << "Generic Pair" << std::endl; }
};

// Partial specialization for second type = int
template <typename T>
class Pair<T, int> {
public:
    void show() { std::cout << "Pair with int specialization" << std::endl; }
};

int main() {
    Pair<double, char> p1; // Generic Pair
    Pair<std::string, int> p2; // Pair with int specialization

    p1.show();
    p2.show();
    return 0;
}

  * 
  * 


*** MÜLAKAT:
  * Soru: Sınıf şablonları neden kullanılır?
  * Cevap:
  * Aynı sınıf yapısını farklı tiplerle kullanmak için, kod tekrarını azaltır.
  * 
  * Soru: Full specialization nedir?
  * Cevap:
  * Genel şablonun belirli bir tipe tamamen uyarlanmış özel versiyonudur.
  * 
  * Soru: Partial specialization ile full specialization farkı nedir?
  * Cevap:
  * Full specialization → yalnızca belirli bir tip için uygulanır.
  * Partial specialization → bazı parametreler generic kalır, bazıları sabitlenir.
  * 
  * Soru: Şablonlar ne zaman derlenir?
  * Cevap:
  * Kullanıldığında (instantiation). Yani kullanılmayan şablonlar derlenmez.
  * 
  * 
  * template <typename T> → derleyici tip bağımlı kod üretir.
  * 
  * Sınıf şablonları için hem full specialization hem de partial specialization bilmek önemli.
  * 
  * Fonksiyon şablonlarında partial specialization yoktur, yalnızca sınıflarda vardır.
  * 
  * typename ve class aynı anlama gelir (şablon parametresi için).
  * 
  * Sorularda “Printer<int> ile Printer<std::string> arasındaki farkı açıkla” gibi örnekler gelir.
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 36 - Partial Specialization & Perfect Forwarding & Alias Template
** Variadic Template (Giriş) & Pack Expansion & Fold Expressions (C++17) & Variable Template
******************************************************************************
** Education


* Partial Specialization
  * 
  * Örnek:

///< Primary Template
template <typename T>
void func(T)
{
    std::cout << 1;
}

///< Explicit Specialization
template <>
void func(int*)
{
    std::cout << 2;
}

///< Function Template
template <typename T>
void func(T*)
{
    std::cout << 3;
}

int main()
{
    int* p = nullptr;
    func(p);
}

CEVAP: 3

  * 
  * 


* Primary template
  * 
  * Örnek:
  * 

template <typename T>
struct Myclass {
public:
    Myclass()
    {
        std::cout << "primarey template type T is : " << typeid(T).name() << '\n';
    }
};

template <typename T>
struct Myclass <T*> {
    Myclass()
    {
        std::cout << "Partial spec. T *\n";
    }
}

int main()
{
    Myclass<int> m1;
    Myclass<double> m2;
    Myclass<void> m3;
    Myclass<int*> m4;
    Myclass<double**> m5;
}

  * 
  * 
  * Örnek:
  * 

template <typename T>
struct Myclass {
public:
    Myclass()
    {
        std::cout << "primarey template type T is : " << typeid(T).name() << '\n';
    }
};

template <typename T>
struct Myclass <T&> {

}

int main()
{
    Myclass<int> m1;
    Myclass<double> m2;
    Myclass<void> m3;
    Myclass<int*> m4;
    Myclass<double**> m5;
}

  * 
  * 


* variadic templates
  * 
  * Örnek:
  * 

///< Bu fonksiyon n tane argüman ile çağrılabilir.
///< recursive instantiation

///< Base case olarak ayrı bir template yazılmalıdır.
template <typename T>
void print(const T& t)
{
    std::cout << t << " ";
}

// template <typename ...Ts>
// void foo(Ts ...args) { }

template <typename T, typename ...Ts>
void print(const T&t, Ts& ...args)
{
    ///< Bu durumda bu fonk. 4 tane arg. gönderildiğinde aşağıdaki ile 3 tane olur.
    print(args..);
}

int main()
{
    ///< Bu çağrı sonuçlandığında template parametre paketinde 3 arg. olucak
    print(1, 2.3, "alican", 45f);
}

  * 
  * 


* perfect forwarding
  * 
  * Örnek:
  * 

void func (T x)

int main()
{
    func(12);   ///< Argüman parametre değişkenine kopyalanıyor.
}

///< Ama func yerine foo isimli bir fonk. çağrılır.

void func (T x)

void foo(???)

int main()
{
    // func(12);    ///< Argüman parametre değişkenine kopyalanıyor.
    // foo(arg);    ///< Argüman L-value ya da R-value olabilir
                    ///< Argüman const ya da non-const olabilir
}

  * 
  * 
  * Örnek:
  * 

class Myclass {};

// 1.
void foo (Myclass&)
{
    std::cout << "Myclass&\n";
}

// 2.
void foo (const Myclass&)
{
    std::cout << "const Myclass&\n";
}

// 3.
void foo (Myclass&&)
{
    std::cout << "Myclass&&\n";
}

void call_foo (Myclass& x)
{
    foo(x);
}

void call_foo (const Myclass& x)
{
    foo(x);
}

void call_foo (Myclass&& x)
{
    foo(x);
}

template <typename T>
void call_foo(T&& x)
{
    foo(std::forward<T>(x));
}

int main()
{
    Myclass m;
    const Myclass cm;

    ///< Hangi overload: Gönderilen eleman L-value       -->> 1.
    foo(m);
    call_foo(m);

    ///< Hangi overload: Gönderilen eleman const L-value -->> 2.
    foo(cm);
    call_foo(cm);

    ///< Hangi overload: Gönderilen eleman PR-value      -->> 3.
    foo(Myclass{});
    call_foo(Myclass{});
}

  * 
  * 


* Template Metaprogramming (TMP)
  * Şablonları kullanarak derleme zamanında hesaplama yapma tekniğidir.
  * Aslında C++’ta şablonlar ile “compile-time programlama” yapılır.
  * En çok kullanılan alanlar: 
  *     Tip çıkarımı, matematiksel hesaplamalar, SFINAE, type traits.
  * 
  * Örnek:
  * 

///< Burada faktöriyel derleme zamanında hesaplanır.
///< constexpr sayesinde runtime’da değil, compile-time’da değer çıkarılır.

// Recursive template
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

// Base case
template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "Factorial<5>::value = " << Factorial<5>::value << std::endl; // 120
}

  * 
  * 


* Concepts (C++20)
  * Şablon parametrelerine kısıtlama (constraint) getirmeyi sağlar.
  * Böylece hata mesajları daha anlaşılır olur.
  * Önceden SFINAE ile yapılan birçok kontrol, concepts ile çok daha basit hale geldi.
  * 
  * Örnek:
  * 

///< Eğer concept sağlanmazsa -->> daha anlamlı derleyici hatası alınır.
  
// Concept: sadece sayısal tipler
template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

// Template constrained by concept
template <Number T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 5) << std::endl;      // OK (int)
    std::cout << add(2.5, 4.5) << std::endl;  // OK (double)
    // std::cout << add("a", "b") << std::endl; // ERROR: concept failure
}

  * 
  * 


* Constraints
  * Concept’lerin uygulanma şeklidir.
  * requires ifadesi ile yazılır.
  * 
  * requires -->> ifade tabanlı kontrol yapabilir (ör. a.size() var mı?).
  * 
  * Örnek:
  * 

///< requires Clause
template <typename T>
requires std::is_integral_v<T>  // sadece integral tipler
T multiply(T a, T b) {
    return a * b;
}

int main() {
    std::cout << multiply(3, 4) << std::endl; // OK
    // std::cout << multiply(3.5, 2.1) << std::endl; // ERROR
}

  * 
  * 
  * Örnek:
  * 

///< requires Expression
// T'nin .size() fonksiyonu olmalı
template <typename T>
concept HasSize = requires(T a) {
    { a.size() } -> std::convertible_to<std::size_t>;
};

template <HasSize T>
void printSize(const T& container) {
    std::cout << "Size: " << container.size() << std::endl;
}

#include <vector>
int main() {
    std::vector<int> v = {1, 2, 3};
    printSize(v); // OK
    // printSize(5); // ERROR
}

  * 
  * 


*** MÜLAKAT:
  * Soru: TMP’nin en büyük avantajı nedir?
  * Cevap:
  * Derleme zamanında hesap yaparak runtime maliyetini ortadan kaldırır. 
  *     Ayrıca tip güvenliği sağlar.
  * 
  * Soru: Concepts, SFINAE’den farkı nedir?
  * Cevap:
  * 
  * SFINAE -->> karmaşık ve hatalar anlaşılmaz.
  * 
  * Concepts -->> çok daha okunabilir, hatalar açıklayıcı.
  * 
  * Soru: requires ne işe yarar?
  * Cevap:
  * Template parametrelerinin belirli özellikleri taşımasını şart koşar.
  * 
  * Soru: TMP’nin dezavantajı nedir?
  * Cevap:
  * Aşırı karmaşık kodlara yol açabilir, derleme süresini uzatır.
  * 
  * 
  * TMP -->> derleme zamanı hesaplamaları için kullanılır.
  *     “Compile-time recursion” çok sık çıkar.
  * 
  * Concepts -->> C++20 ile gelen en önemli özelliklerden biri,
  *     SFINAE’nin modern alternatifi.
  * 
  * requires -->> constraints için kritik kelime,
  *     hem “clause” hem “expression” ile kullanılabilir.
  * 
  * Sık sorulan örnek:
  * “Bir şablon fonksiyonun yalnızca std::integral tiplerde çalışmasını 
  *     nasıl sağlarsın?” -->> Concepts/Constraints cevabı beklenir.
  * 
  * 
***


* Partial Specialization (Kısmi Özelleştirme)
  * Yalnızca class templates için geçerlidir.
  * Genel şablonun bir kısmı sabitlenir, diğer kısmı generic kalır.
  * 
  * Örnek:
  * 

// Genel şablon
template <typename T1, typename T2>
class Pair {
public:
    void show() { std::cout << "Generic Pair" << std::endl; }
};

// İkinci tip int olursa özel davranış
template <typename T>
class Pair<T, int> {
public:
    void show() { std::cout << "Partial specialization: second is int" << std::endl; }
};

int main() {
    Pair<double, char> p1;   // Genel
    Pair<std::string, int> p2; // Kısmi özelleştirme

    p1.show(); // Generic Pair
    p2.show(); // Partial specialization: second is int
}

  * 
  * 


* Perfect Forwarding (Mükemmel İletim)
  * T&& (universal reference) + std::forward<T> kullanılır.
  * Argümanı değer kategorisini (lvalue/rvalue) bozmadan başka bir fonksiyona iletir.
  * 
  * Örnek:
  * 

void printValue(const int& x) { std::cout << "Lvalue: " << x << std::endl; }
void printValue(int&& x)      { std::cout << "Rvalue: " << x << std::endl; }

template <typename T>
void forwarder(T&& arg) {
    printValue(std::forward<T>(arg)); // mükemmel iletim
}

int main() {
    int a = 10;
    forwarder(a);   // Lvalue
    forwarder(20);  // Rvalue
}

  * 
  * 


* Alias Template (Şablon Takma Adı)
  * typedef yerine using ile şablonlara takma ad verilebilir.
  * 
  * Örnek:
  * 

// Alias template
template <typename T>
using Vec = std::vector<T>;

int main() {
    Vec<int> v = {1, 2, 3};
    for (auto n : v) std::cout << n << " ";
}

  * 
  * 


* Variadic Template (Giriş)
  * Sınırsız sayıda parametre alabilen şablonlardır.
  * 
  * Örnek:
  * 

template <typename... Args>
void printAll(Args... args) {
    (std::cout << ... << args) << std::endl; // fold expression
}

int main() {
    printAll(1, 2.5, "Hello", 'A'); // 1 2.5 Hello A
}

  * 
  * 


* Pack Expansion (Parametre Açılımı)
  * '...' operatörü ile parametreler açılır.
  * 
  * Örnek:
  * 

template <typename... Args>
void printEach(Args... args) {
    ( (std::cout << args << " "), ... ); // parametreleri açar
}

int main() {
    printEach(10, 20, 30, "end");
}

  * 
  * 

* Fold Expressions (C++17)
  * Variadic parametreler üzerinde toplama, çarpma vb. işlemleri kolaylaştırır.
  * 
  * Örnek:
  * 

template <typename... Args>
auto sum(Args... args) {
    return (args + ...); // fold expression
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5) << std::endl; // 15
}

  * 
  * 


* Variable Templates
  * Değişkenleri de şablonlaştırır.
  * 
  * Örnek:
  * 

// Generic constant
template <typename T>
constexpr T pi = T(3.1415926535897932385);

int main() {
    std::cout << pi<double> << std::endl;
    std::cout << pi<float> << std::endl;
}

  * 
  * 


*** MÜLAKAT:
  * Partial vs Full Specialization farkı nedir?
  * Cevap:
  * Full -->> tamamen belirli tipe özel.
  * Partial -->> bir kısmı generic kalır.
  * 
  * Perfect forwarding neden önemlidir?
  * Cevap:
  * Fonksiyon argümanını değer kategorisini (lvalue/rvalue) koruyarak başka fonksiyona iletir.
  * 
  * Variadic templates nerelerde kullanılır?
  * Cevap:
  * std::tuple, std::make_shared, std::format, sınırsız argüman fonksiyonlarında.
  * 
  * Fold expression nedir?
  * Cevap:
  * Variadic parametreleri toplama/çarpma gibi işlemlerle kolayca birleştirme yöntemidir.
  * 
  * Variable template nerede kullanılır?
  * Cevap:
  * Tip bağımlı sabitler (pi<float>, pi<double>) veya compile-time değerlerde.
  * 
  * 
  * template <typename T> ile yazılan şablonlar derleme zamanında çözülür.
  * 
  * T&& her zaman rvalue reference değildir -->> universal reference olabilir.
  * 
  * Variadic template + fold expression -->> en sık mülakat sorusu!
  * 
  * Alias template ile typedef farkını sorabilirler.
  * 
  * Variable templates genellikle matematiksel sabitler için kullanılır.
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 37 - STL (Standard Template Library) & Iterators
******************************************************************************
** Education


* STL (Standard Template Library)
  * Containers : Temel veri yapılarını implement eden veri şablonlarıdır.
  * Iterators  : Container'larda tutulan ögelerin konum bilgisini kullanır.
  * Algorithms : Algoritmaları implement eden generic fonk.'dır.
  * 
  * Algoritmalar parametresi iterator olan fonksiyonlardır.
  * Algoritmalar iterator parametreleri ile üstünde işlem yapacağı
  *     veri yapısındaki ögelere erişim sağlıyor.
  * 
  * 


* Containers : 
  * Container veri yapılarını implement eden sınıflardır.
  * 
  * Sequence containers : ...
  * std::vector : Dinamik dizi sınıfıdır.
  * std::deque : Dinamik dizilerin dizisidir. Elemanları dizi olan bir dizidir.
  * std::list : Çifte bağlı liste sınıfıdır.
  * std::forward_list : Teke bağlı liste sınıfıdır.
  * std::array : C dizilerini sarmalayan, onları STL uyumlu ve güvenli hale getirir.
  * std::string : 
  * 
  * Associative containers : Önceden verilmiş değerler arasında arama ve sorgu yapar.
  * std::set : Sadece bir key tutulabilir.
  * std::multiset : Birden fazla key tutulabilir.
  * td::map : Anahtar değer çiftleridir. Anahtarla arama yapıp bulunca anahtarla eşleştiriyor
  * std::multimap : Birden fazla anahtar tutulabilir.
  * 
  * Unordered associative containers : Hash-Table veri yapısıdır.
  * std::unordered_set : ...
  * std::unordered_multiset : ...
  * std::unordered_map : ...
  * std::unordered_multimap : ...
  * 
  * 


* Örnek:
  * 
  * Örnek-1:
  * 

template <typename Iter>
void print_array (Iter beg, Iter end)
{
    while (beg != end)
    {
        std::cout << *beg << ' ';
        ++beg;
    }
    
    std::cout << '\n';
}

int main()
{
    std::vector<double> dvec{1.2, 3.4, 5.6, 7.8, 9.1};
    
    print_array(dvec.begin(), dvec.end());

    std::list<std::string> names{"alpha", "beta", "charlie", "delta", "echo"};

    print_array(names.begin(), names.end());

}

  * 
  * Örnek-2:
  * 

int main()
{
    using namespace std;

    ///< vector açılımı nasıl yapılır?
    ///< 1. yöntem : vector<int> ivec{12, 34, 56, 78};

    ///< begin() değerinin geri dönüş türünü tutacak bir değişken istersen:
    ///< 1. yöntem : vector<int>::iterator iter = ivec.begin();
    ///< 2. yöntem : auto iter = ivec.begin();


    list<string> slist;
    auto iter = slist.begin();
}

  * 
  * Örnek:
  * 

///< Bir container ilk üyesine iterator almak için non-static member func olan begin() çağrılır.
int main ()
{
    using namespace std;

    vector<int> ivec(1000);
    ivec.begin();   ///< Alternatif
    begin(ivec);    ///< Alternatif

    vector<int> ivec(1000);
    int ar[100]{};
    auto iter = begin(ivec);
}

  * 
  * 


* Iterator category
  * output iterator         : 
  *     copy construtible
  *     ++it it++
  *     *it it-> (R-value)
  *     ostream_iterator - ostreambuf_iterator
  * 
  * input iterator          : 
  *     copy constructible
  *     ++it it++
  *     *it it-> (L-value)
  *     istream_iterator - ostreambuf_iterator
  * 
  * forward iterator        : 
  *     intput ve output
  *     forward_list-unordered hash-table
  * 
  * bidirectional operator  : 
  *     input + output iterator
  *     --it it-- 
  *     list-set multiset- map multimap
  * 
  * random access iterator  : 
  *     bidirectional iterator
  *     C prog. operasyonlarını destekler.
  *     vector - deque - array - string - C array
  * 
  * Örnek:
  * 

int main()
{
    ///< vector iteratorleri nedir? Random access iteratordur.
    vector<int> ivec(100);
    auto iter1 = ivec.begin();
    auto iter2 = ivec.begin();

    *iter1;                 // Hata yok
    ++iter1;                // Hata yok
    --iter1;                // Hata yok

    iter1 += 5;             // Hata yok
    iter1 - iter2;          // Hata yok
    iter2[12];              // Hata yok

    iter1 < iter2;          // Hata yok
}

  * 
  * Örnek:
  * 

int main()
{
    ///< list iteratorleri nedir? Random access iteratordur.
    list<int> ilist(100);
    auto iter1 = ilist.begin();
    auto iter2 = ilist.begin();

    *iter1;         // Hata yok
    ++iter1;        // Hata yok
    --iter1;        // Hata yok

    iter1 += 5;     // Hata var
    iter1 - iter2;  // Hata var
    iter2[12];      // Hata var

    iter1 < iter2;  // Hata var
}

  * 
  * 


* Örnekler:
  * 
  * Örnek-1:
  * 

template <typename T, typename U>
struct IsSame : std::false_type {};

template <typename T>
struct IsSame<T, T> : std::true_type {};

template <typename T, typename U>
constexpr bool IsSame_v = IsSame<T, U>::value;

int main()
{
    IsSame<int, double>::value; ///< false_type
    IsSame<int, int>::value;    ///< true_type
    IsSame<int, double>;        ///< false_type
}

  * 
  * Örnek-2:
  * 

///< Iteratorun random access iterator olup olmadığı nasıl test edilir?
template<typename Iter>
void algo(Iter beg, Iter end)
{
    ///< Iteratorun iterator türü Random Access Iterator Tag ise
    if constexpr(std::is_same_v<typename Iter::iterator_category, std::random_access_iterator_tag>)
    {
        // TODO: Do Sth.
    }
    ///< Iteratorun iterator türü Bidirectional Access Iterator Tag ise
    else if constexpr(std::is_same_v<typename Iter::iterator_category, std::bidirectional_access_iterator_tag>)
    {
        // TODO: Do Sth.
    }
    else
    {
        // TODO: Do Nothing.
    }
}

  * 
  * 


* STL (Standard Template Library)
  * STL, C++’ta veri yapıları ve algoritmaları şablon tabanlı sağlayan kütüphanedir.
  * 
  * 3 temel bileşenden oluşur:
  *     Containers (Kapsayıcılar) -->> veri yapıları (vector, list, map…)
  *     Algorithms (Algoritmalar) -->> hazır fonksiyonlar (sort, find, count…)
  *     Iterators (Yineleyiciler) -->> kapsayıcı elemanlarını dolaşma aracı
  * 
  * 


* 1. Containers (Kapsayıcılar)
  * Sequence Containers: vector, deque, list, forward_list, array
  * 
  * Associative Containers: set, multiset, map, multimap
  * 
  * Unordered Containers (C++11+): unordered_set, unordered_map
  * 
  * Container Adapters: stack, queue, priority_queue
  * 
  * Örnek:
  * 

int main() {
    std::vector<int> v = {4, 2, 8, 1};

    std::sort(v.begin(), v.end()); // STL algoritması

    for (int n : v)
        std::cout << n << " ";  // 1 2 4 8
}

  * 
  * 


* 2. Algorithms (Algoritmalar)
  * STL algoritmaları iteratorlar üzerinde çalışır.
  * 
  * Örnekler: sort, find, count, accumulate, for_each.
  * 
  * Örnek:
  * 

  int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    auto it = std::find(v.begin(), v.end(), 3);
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
}

  * 
  * 


* 3. Iterators (Yineleyiciler)
  * Iterator = pointer benzeri nesne, kapsayıcıların elemanlarını dolaşmaya yarar.
  * Türleri:
  *     Input Iterator -->> sadece okuma (istream_iterator)
  *     Output Iterator -->> sadece yazma (ostream_iterator)
  *     Forward Iterator -->> ileri yönde okuma-yazma (forward_list)
  *     Bidirectional Iterator -->> ileri & geri (list, set, map)
  *     Random Access Iterator -->> pointer gibi ileri-geri atlama (vector, deque, array)
  * 
  * Örnek:
  * 

  int main() {
    std::vector<int> v = {10, 20, 30};

    // Iterator ile dolaşma
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
}

///< Modern C++ ile:
for (auto it = v.begin(); it != v.end(); ++it) { ... }
for (int n : v) { ... }  // range-based for

  * 
  * 


*** MÜLAKAT:
  * Soru: STL’in avantajları nelerdir?
  * Cevap:
  * Generic (her tip için çalışır)
  * Performanslı (çoğu algoritma O(N log N) veya O(N))
  * Test edilmiş, güvenilir
  * 
  * Soru: vector ile list farkı nedir?
  * Cevap:
  * vector -->> random access hızlıdır, ortadan ekleme/silme yavaştır.
  * list -->> ortadan ekleme/silme hızlıdır, random access yoktur.
  * 
  * Soru: Random access iterator hangi kapsayıcılarda vardır?
  * Cevap:
  * vector, deque, array.
  * 
  * Soru: map ile unordered_map farkı nedir?
  * Cevap:
  * map -->> balanced tree, sıralı, O(log N).
  * unordered_map -->> hash tabanlı, sırasız, O(1) average.
  * 
  * 
  * STL = Container + Algorithm + Iterator üçlüsü akılda tut.
  * Algoritmalar kapsayıcıya değil, iteratöre uygulanır. Bu en sık sorulan noktalardan biri.
  * İleri seviye mülakatta, vector reallocation, map vs unordered_map performans farkları sorulabilir.
  * begin() -->> ilk eleman, end() -->> sonrasını gösterir (son elemanı değil!).
  * Modern C++’ta auto ve range-based for iterator kullanımını kolaylaştırır.
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 38 - Algorithms
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 39 - STL'deki Iteratorleri Manipüle Eden Algoritmalar
******************************************************************************
** Education

*** MÜLAKAT:
* MÖHÜÖM
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 40 - Lambda Expressions
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 41 - Containerlar & Vector
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 42 - Vector Üye Fonksiyonları
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 43 - Vector Mutator Fonksiyonları Devam & STL'deki Silme Algoritmaları
** Std::Ostream_Iterator
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 44 - Iterator Invalidation & Std::Deque (Double Ended Queue) & Sorting Algorithms
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 45 - Std::List ve Std::Forward_List &
** Sorted Range Algorithms (Sıralı Range Algoritmaları)
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 46 - Forward List (Tekli Bağlı Liste) & Container Adapters & Stack
** Queue & Priority_Queue & Associative Containers (Set, Multiset, Map, Multimap)
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 47 - Set Devam & Map & Unordered Associative Containers & Hash Table (Çırpılama Tablosu)
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 48 - Unordered Associative Containers Devam & Function Adapters
** Reference_Wrapper & Std::Bind
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 49 - Std::Bind Devam & Std::Function & Memfn ve Notfn Adaptorleri
** Std::Array
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 50 - Std::Tuple (Demet, Bağ) & Std::Invoke & Function Pointers
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 51 - Data Member Pointers & Std::Bitset & Dinamik Ömürlü Nesneler
******************************************************************************
** Education

*** MÜLAKAT:
* MÖHÜÖM
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 52 - Smart Pointers & Unique_Ptr
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 53 - Shared_Ptr
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 54 - Weak_Ptr & CRTP (Curiously Recurring Template Pattern) Giriş
** Sınıflara Statik Üye Fonksiyonu Olarak Operator New ve Delete Yazmak
******************************************************************************
** Education

*** MÜLAKAT:
* MÖHÜÖM
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 55 - Input-Output Operations & Format State
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 56 - Istringstream & Condition State & Std::Istream_Iterator
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 57 - Dosya Üstünde Okuma/Yazma İşlemleri & Format Mini-Giriş (C++20)
** Stream'de Dosya Devam & Okuma İşleri & Formatsız Okuma/Yazma
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 58 - Ara Konu: C++ Popüler Hataları & File Stream İşlemleri Devam
******************************************************************************
** Education

*** MÜLAKAT:
* MÖHÜÖM
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 59 - Lambda Devam & Lambda Init Capture & Class Member Fonksiyonu Lambda Kullanımı
** Std::Ratio & Std::Chrono
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 60 - Std::Chrono Devam & Std::Duration İle İşlemler
** User Defined Literals & Std::Chrono Literalleri & Time_Point Sınıfı
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO 61 - System_Clock Sınıfı & Vocabulary Types (Std::Any, Std::Optional, Std::Variant)
** Std::Optional Sınıf Şablonu & Std::Variant Sınıf Şablonu
******************************************************************************
** Education


* 
  * 
  * 


*** MÜLAKAT:
  * 
  * 
***

******************************************************************************/  
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
** VIDEO - QUIZ
******************************************************************************
** Education

RESULT:
SEVİYE    ADET  1-DOĞRU   1-YANLIŞ  ****  2-DOĞRU   2-YANLIŞ
KOLAY      25     20          05    ****    XX          XX
ORTA       36     22          14    ****    XX          XX
ZOR        06     04          02    ****    XX          XX
TOPLAM:    67     46          21    ****    XX          XX
******************************************************************************/
