# 🎮 so_long

**so_long**, École 42 müfredatının bir parçası olarak geliştirilmiş 2D bir oyun projesidir. Oyuncu bir labirentte gezinir, mücevherler toplar, düşmanlardan kaçınır ve çıkışı bulur.

## 📹 Demo Video

https://github.com/user-attachments/assets/9768efa4-4647-481f-8eb0-f4adddef1c29

## 🎯 Oyun Amacı

Oyuncu şunları yapmalıdır:
- 🏃 Ok tuşları veya WASD kullanarak harita üzerinde gezinmek
- 💎 Seviye boyunca dağılmış tüm mücevherleri (C) toplamak
- 🚪 Tüm mücevherleri topladıktan sonra çıkış kapısına (E) ulaşmak
- ⚠️ Bölgede bulunan düşmanlardan (X) kaçınmak
- 📈 Seviyeyi minimum adımla tamamlamak

## 🎮 Kontroller

| Tuş | Hareket |
|-----|---------|
| `W` / `↑` | Yukarı Hareket |
| `A` / `←` | Sola Hareket |
| `S` / `↓` | Aşağı Hareket |
| `D` / `→` | Sağa Hareket |
| `Q` / `ESC` | Oyundan Çık |

## 🗺️ Harita Elementleri

| Sembol | Element | Açıklama |
|--------|---------|----------|
| `1` | Duvar | Geçilmez engeller |
| `0` | Boş Alan | Yürünebilir alan |
| `P` | Oyuncu | Başlangıç pozisyonu |
| `C` | Toplanabilir | Toplanacak mücevherler |
| `E` | Çıkış | Seviyeyi tamamlamak için kapı |
| `X` | Düşman | Tehlikeli engeller |

## 🛠️ Kurulum ve Derleme

### Gereksinimler
- Linux işletim sistemi
- X11 geliştirme kütüphaneleri
- Make
- GCC derleyici

### Kurulum
```bash
# Depoyu klonlayın
git clone https://github.com/keyiflerolsun/so_long.git
cd so_long

# MiniLibX Kütüphanesini klonlayın
git clone https://github.com/42Paris/minilibx-linux.git

# Projeyi derleyin
make

# Oyunu bir harita ile çalıştırın
./so_long maps/default.ber
```

### Derleme Dosyalarını Temizleme
```bash
make clean    # Nesne dosyalarını kaldır
make fclean   # Nesne dosyalarını ve çalıştırılabilir dosyayı kaldır
make re       # Her şeyi yeniden derle
```

## 📁 Proje Yapısı

```
so_long/
├── src/                   # Kaynak kod dosyaları
│   ├── so_long.h          # Ana başlık dosyası
│   ├── init_game.c        # Oyun başlatma
│   ├── render.c           # Render fonksiyonları
│   ├── move_utils.c       # Oyuncu hareketi
│   ├── map_utils.c        # Harita doğrulama
│   ├── player_utils.c     # Oyuncu mekaniği
│   ├── enemy_utils.c      # Düşman davranışı
│   ├── gem_utils.c        # Toplanabilir mekaniği
│   ├── door_utils.c       # Çıkış kapısı mantığı
│   ├── wall_utils.c       # Duvar render
│   └── text_utils.c       # UI metin render
├── maps/                  # Oyun haritaları
│   ├── default.ber        # Temel seviye
│   ├── big.ber            # Büyük seviye
│   └── *.ber              # Çeşitli test haritaları
├── textures/              # Oyun sprite'ları
│   ├── wall/              # Duvar dokuları
│   ├── ply/               # Oyuncu animasyonları
│   ├── gem/               # Mücevher animasyonları
│   ├── door/              # Kapı durumları
│   └── enemy/             # Düşman sprite'ları
├── libft/                 # Özel C kütüphanesi
├── ft_printf/             # Özel printf uygulaması
├── get_next_line/         # Dosya okuma yardımcısı
├── minilibx-linux/        # Grafik kütüphanesi
└── main.c                 # Giriş noktası
```

## 🎨 Özellikler

### Grafikler ve Animasyon
- 🖼️ Özel piksel sanatı dokuları (64x64px)
- 🎬 Oyuncu, mücevher ve düşmanlar için animasyonlu sprite'lar
- 🚪 Dinamik kapı animasyonları
- 💫 Yumuşak hareket geçişleri

### Oyun Mekaniği
- ✅ Harita doğrulama (duvarlar, tek oyuncu/çıkış, yol kontrolü)
- 🔄 Yol doğrulama için flood fill algoritması
- 📊 Adım sayacı gösterimi
- 🏆 Skor takibi
- ⚡ Oyun döngüsü ile gerçek zamanlı render

### Harita Sistemi
- 📝 `.ber` dosya formatı desteği
- 🧪 Dahil edilmiş çoklu test haritaları
- 🔍 Kapsamlı harita doğrulama
- 🌊 Flood fill algoritması tamamlanabilirliği sağlar

## 🗺️ Özel Harita Oluşturma

Haritalar şu kurallara uymalıdır:
1. **Dosya uzantısı**: `.ber`
2. **Gerekli elementler**: 
   - Tam olarak bir Oyuncu (`P`)
   - Tam olarak bir Çıkış (`E`)
   - En az bir Toplanabilir (`C`)
3. **Harita dikdörtgen olmalı**
4. **Duvarlarla (`1`) çevrili olmalı**
5. **Geçerli yol bulunmalı** oyuncudan tüm toplanabilir ve çıkışa

### Örnek Harita
```
1111111111111
1000000000001
1000011111101
1P0X00E00C1C1
1111111111111
```

## 🧪 Mevcut Haritalar

| Harita | Açıklama | Zorluk |
|--------|----------|--------|
| `default.ber` | Basit giriş seviyesi | Kolay |
| `big.ber` | Düşmanlı büyük labirent | Orta |
| `map.ber` | Standart test seviyesi | Kolay |
| `map2.ber` | Alternatif düzen | Kolay |
| `empty.ber` | Minimal test durumu | Kolay |

## 🏗️ Teknik Uygulama

### Kullanılan Kütüphaneler
- **MiniLibX**: Grafikler ve pencere yönetimi
- **Özel libft**: Standart C kütüphane fonksiyonları
- **ft_printf**: Özel printf uygulaması
- **get_next_line**: Verimli dosya okuma

### Ana Algoritmalar
- **Flood Fill**: Harita doğrulama ve yol kontrolü
- **Oyun Döngüsü**: Sürekli render ve girdi işleme
- **Bellek Yönetimi**: Uygun tahsis/serbest bırakma
- **Hata İşleme**: Kapsamlı hata kontrolü

## 🤝 École 42 Projesi

Bu proje 42 İstanbul müfredatının bir parçasıdır ve şunları gösterir:
- **Grafik Programlama**: MiniLibX kullanımı
- **Oyun Geliştirme**: Temel oyun mekaniği
- **Algoritma Uygulaması**: Flood fill, doğrulama
- **Bellek Yönetimi**: Uygun kaynak işleme
- **Hata İşleme**: Sağlam hata kontrolü
- **Kod Organizasyonu**: Temiz, modüler yapı

---

*42 İstanbul'da ❤️ ile yapıldı*
