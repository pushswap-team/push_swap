*Bu proje bdayakli, bayseven tarafından 42 müfredatının bir parçası olarak oluşturulmuştur.*

# Push_Swap: Adaptif Sıralama Algoritması

## Açıklama
Push_Swap projesi oldukça basit ve son derece etkili bir algoritma projesidir: verilerin sıralanması gerekir. Elinizde bir dizi tam sayı, 2 adet yığın (stack) ve bu iki yığını manipüle etmek için bir dizi talimat bulunmaktadır. Amaç, argüman olarak alınan tam sayıları sıralayan ve Push_Swap dilindeki talimatlardan oluşan en küçük programı hesaplayıp standart çıktıya (stdout) yazdıran bir C programı yazmaktır.

**Proje Özeti:**
Bu depo, Push_Swap'ın özel ve son derece optimize edilmiş bir versiyonunu içerir. Tüm girdiler için tek bir algoritma kullanan standart uygulamaların aksine, programımız bir **Adaptif Sıralama Motoru (Adaptive Sorting Engine)** içerir. Girdi verilerini analiz eder, bir "karmaşıklık yüzdesi (disorder percentage)" hesaplar ve en verimli sıralama stratejisini dinamik olarak seçer. Ayrıca standart çıktıyı bozmadan zaman karmaşıklığını, operasyon sayılarını ve strateji detaylarını loglamak için özel bir benchmark (performans testi) moduna sahiptir.

---

## Talimatlar

### Derleme
Projeyi derlemek için deponun kök dizininde bulunan Makefile'ı kullanmanız yeterlidir.

```bash
# Ana programı derler
make

# Obje (nesne) dosyalarını temizler
make clean

# Program dahil her şeyi temizler
make fclean

# Her şeyi baştan derler
make re
```

### Çalıştırma
Programı tek bir string veya çoklu argüman olarak formatlanmış bir tam sayı listesi ile çalıştırın.

```bash
# Standart çalıştırma
./push_swap 4 67 3 87 23

# Özel flag'ler (bayraklar) ile çalıştırma
./push_swap --complex 4 67 3 87 23
```

**Kullanılabilir Flag'ler:**
* `--simple`: Basit stratejiyi zorunlu kılar (Selection/Bubble temelli).
* `--medium`: Orta stratejiyi zorunlu kılar (Chunking/Bucket temelli).
* `--complex`: Karmaşık stratejiyi zorunlu kılar (Radix bitwise sıralama).
* `--adaptive`: Karmaşıklığı analiz eder ve otomatik olarak seçim yapar (Hiçbir flag verilmezse varsayılan davranış budur).
* `--bench`: Benchmark verilerini (karmaşıklık yüzdesi, strateji adı, toplam operasyon vb.) standart hata (stderr) üzerinden loglar.

*Benchmark kullanım örneği:*
```bash
./push_swap --bench --adaptive 5 4 3 2 1 2> bench.log > /dev/null && cat bench.log
```

---

## Algoritma Açıklaması ve Gerekçelendirme

Uygulamamız, farklı veri seti boyutları ve durumlarında olası en düşük talimat sayısını garanti etmek için birden fazla stratejiye dayanmaktadır.

### 1. Basit Strateji (Simple - O(n^2))
* **Açıklama:** En küçük elemanı iteratif olarak bulup B yığınına iten ve ardından A yığınına geri döndüren doğrudan bir yaklaşımdır (Selection Sort'a benzer).
* **Gerekçe:** O(n^2) büyük girdiler için matematiksel olarak verimsiz olsa da, çok küçük diziler (örn. 3 ila 5 sayı) veya zaten neredeyse sıralı olan diziler için son derece kısa talimat setleri üretir. Bu durumlarda karmaşık algoritmaların getirdiği ek yüke (overhead) gerek yoktur.

### 2. Orta Strateji (Medium - O(n√n))
* **Açıklama:** Parçalama (chunking) veya kova (bucket) yaklaşımı kullanır. Veriler orantılı segmentlere bölünür, bu da sayı gruplarını B yığınına itmemize ve ardından A yığınına dönerken onları sıralamamıza olanak tanır.
* **Gerekçe:** Bu bir orta yol optimizasyonudur. O(n^2)'nin çok maliyetli hale geldiği, ancak Radix'in katı bit tabanlı işlemlerinin gereğinden fazla döndürme (rotate) yapabileceği orta boyutlu girdiler için oldukça etkilidir.

### 3. Karmaşık Strateji (Complex - O(n log n) / Radix O(d * n))
* **Açıklama:** Bit seviyesinde bir **Radix Sort** (Taban Sıralaması) uyguladık. Sıralamadan önce, negatif sayıları ve büyük boşlukları yönetmek için girdi indekslere sıkıştırılır (Koordinat Sıkıştırması). Ardından algoritma, sağa bit kaydırma (`>>`) ve VE (`& 1`) işlemlerini kullanarak sayıları ikilik (binary) gösterimlerine göre sıralar.
* **Gerekçe:** Bu, büyük girdileri (100 ila 500 sayı) sıralamadaki çekirdek yapımızdır. 0'ları ve 1'leri bit seviyesinde ayırarak istikrarlı ve son derece öngörülebilir bir çalışma süresi sağlıyoruz. 42'nin katı performans gereksinimlerini (100 sayı için <700 işlem, 500 sayı için <5500 işlem) rahatlıkla geçmektedir.

### 4. Adaptif Strateji (Varsayılan - Adaptive)
* **Gerekçe:** Her duruma uyan tek bir algoritma yaklaşımı kusurludur. Bir **Karmaşıklık Yüzdesi (Disorder Percentage)** oluşturmak için her sayının hedef konumuyla arasındaki "mesafeyi" hesaplıyoruz. Bu yüzdeye ve toplam eleman sayısına dayanarak, program verileri otomatik olarak Basit, Orta veya Karmaşık motora yönlendirir ve dinamik olarak maksimum verimliliği sağlar.

---

## Kaynaklar

**Klasik Referanslar:**
* *Push_Swap görselleştiricileri (visualizers):* Yığın (stack) hareketlerini debug etmek (hata ayıklamak) için yaygın olarak kullanıldı.
* *Radix Sort ve Bitwise İşlemleri:* Standart ikilik (binary) sıralama uygulamaları ve negatif tam sayılarla "two's complement" (ikiye tümleyen) davranışları araştırıldı.
* *Koordinat Sıkıştırması (Coordinate Compression):* Dizileri `0...N-1` aralığına güvenli bir şekilde haritalamak için indeksleme teknikleri incelendi.

**Yapay Zeka Kullanımı:**
Bu projenin geliştirilmesi sırasında aşağıdaki belirli görevler için Yapay Zeka kullanılmıştır:
1.  **Yeniden Düzenleme (Refactoring) ve Norminette:** Ana fonksiyonlardaki (main.c gibi) satır sayılarını 42'nin katı 25 satırlık Norminette kuralına uygun şekilde azaltmak için fikir alışverişi yapıldı, özellikle gereksiz değişkenlerin kaldırılması kavramsallaştırıldı.
2.  **Teorik Anlayış:** Akran değerlendirmesi (peer evaluation) savunmasına daha iyi hazırlanmak için O(n log n) ile Radix Sort'un gerçek O(d * n) karmaşıklığı arasındaki matematiksel farklar tartışıldı.
3.  **Dokümantasyon Formatlama:** Tüm değerlendirme gereksinimlerinin ve markdown formatlama standartlarının profesyonelce karşılandığından emin olmak için bu `README.md` dosyasının yapılandırılmasına ve taslağının oluşturulmasına yardımcı oldu.