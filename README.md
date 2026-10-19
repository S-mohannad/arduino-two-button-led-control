# 🔘 Two-Button LED On/Off Control

> **Arduino Project #27** — زران مستقلان لتشغيل وإطفاء LED

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

مشروع يتحكم بـ LED عبر زرين مستقلين:

- **زر pin 7:** يضغطه → LED يشتغل
- **زر pin 8:** يضغطه → LED يطفى
- كلا الزرين يستخدمان `INPUT_PULLUP` — يقرآن 0 عند الضغط و1 عند الإفراج
- LED يحافظ على حالته الأخيرة حتى يُضغط الزر الآخر

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│             7 ●─┼──────────── زر ON  ── GND
│             8 ●─┼──────────── زر OFF ── GND
│             2 ●─┼──[220Ω]──💡 LED ── GND
└─────────────────┘
```

- 🔘 زر ON على Pin 7 موصول إلى GND (INPUT_PULLUP)
- 🔘 زر OFF على Pin 8 موصول إلى GND (INPUT_PULLUP)
- 💡 LED على Pin 2 مع مقاومة 220Ω

---

## 💡 Concepts Used

- `INPUT_PULLUP` — مقاومة سحب داخلية، الزر يقرأ 0 عند الضغط و1 عند الإفراج
- `digitalRead()` — قراءة حالة كل زر
- `&&` — شرط مزدوج للتحقق من حالة الزرين معاً
- `digitalWrite()` — تشغيل وإطفاء LED
- **State retention** — LED يحافظ على حالته بين الضغطات

---

## 📊 Behavior

| pin 7 | pin 8 | التأثير |
|-------|-------|---------|
| مضغوط (0) | مُفرَج (1) | LED يشتغل |
| مُفرَج (1) | مضغوط (0) | LED يطفى |
| كلاهما مُفرَج | — | لا تغيير |

---

## 🔗 Code

```cpp
void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  if (digitalRead(7) == 0 && digitalRead(8) == 1)
    { digitalWrite(2, HIGH); }
  if (digitalRead(7) == 1 && digitalRead(8) == 0)
    { digitalWrite(2, LOW); }
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل الدائرة (زر ON على pin 7، زر OFF على pin 8، LED على pin 2)
3. انسخ الكود والصقه في المحرر
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. اضغط زر pin 7 لتشغيل LED، واضغط زر pin 8 لإطفائه

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
