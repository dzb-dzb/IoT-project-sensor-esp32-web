# 🌡️ Dự án: dzb Weather Station

Hệ thống giám sát nhiệt độ và độ ẩm thời gian thực sử dụng **ESP32**, truyền dữ liệu lên Server và hiển thị trực quan qua trang Web giúp người dùng có thể truy cập dễ dàng qua Internet.

🔗 **Link truy cập trang web:** [Tại đây](https://dzb-dzb.github.io/IoT-project-sensor-esp32-web/)

---

### 🚀 Tính năng chính
* **Đọc dữ liệu:** Thu thập thông số từ cảm biến độ chính xác cao (DHT22).
* **Kết nối:** Tích hợp WiFi và truyền dữ liệu qua giao thức HTTP.
* **Giám sát:** Giao diện Web hiển thị biểu đồ nhiệt độ và độ ẩm trực quan theo thời gian thực.

---

### 🛠 Kiến trúc hệ thống (Technical Stack)

#### 📟 1. Firmware (ESP32)
* **Ngôn ngữ/Framework:** C/C++, Arduino IDE.
* **Thư viện chính:** `WiFi.h`, `HTTPClient.h`, `DHT.h`.
* **Tính năng cốt lõi:**
    * Đọc dữ liệu môi trường từ cảm biến DHT22.
    * Cơ chế tự động quản lý và kết nối lại WiFi khi mất tín hiệu (Auto-reconnect).
    * Đóng gói dữ liệu thô sang định dạng JSON để tối ưu hóa quá trình truyền tải.

#### 🖥️ 2. Backend (Server)
* **Công nghệ:** Node.js (Express Framework).
* **Thư viện sử dụng:** `express`, `cors`, `body-parser`.
* **Chức năng chính:**
    * **REST API:** Cung cấp các Endpoint để ESP32 gửi dữ liệu lên (POST) và Web lấy dữ liệu về (GET).
    * **Xử lý dữ liệu:** Tiếp nhận và định dạng dữ liệu JSON từ thiết bị đầu cuối.
    * **Kết nối:** Cấu hình CORS cho phép Frontend truy cập vào API an toàn.

#### 🌐 3. Frontend (Web Dashboard)
* **Công nghệ:** HTML5, CSS3, JavaScript (Vanilla JS).
* **Chức năng chính:**
    * **Data Fetching:** Sử dụng JavaScript để gọi API từ Server và lấy dữ liệu cảm biến mới nhất.
    * **Dynamic UI:** Tự động cập nhật dữ liệu vào các cột hiển thị mà không cần tải lại trang.
    * **Visualization:** Sử dụng CSS để tạo hình, định dạng kích thước và màu sắc cho các cột dữ liệu trực quan.
    * **Thiết kế:** Giao diện tối giản, tập trung tối đa vào việc hiển thị thông số.

---

### 🔌 Yêu cầu phần cứng (Hardware Requirements)
* **Board điều khiển:** ESP32 DevKit V1
* **Cảm biến:** DHT22 (Nhiệt độ & Độ ẩm)
* **Phụ kiện:** Breadboard, dây cắm (Jumper wires), cáp Micro USB.

---
*Dự án được thực hiện bởi **dzb**.*
