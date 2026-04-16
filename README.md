### Dự án: dzb Weather Station
Hệ thống giám sát nhiệt độ, độ ẩm thời gian thực sử dụng ESP32, gửi dữ liệu lên server và hiển thị dữ liệu qua trang web có thể truy cập dễ dàng bằng internet.
Link truy cập trang web [tại đây](https://dzb-dzb.github.io/IoT-project-sensor-esp32-web/)
### Tính năng chính
- Đọc dữ liệu từ cảm biến (DHT22).
- Kết nối WiFi và truyền dữ liệu qua giao thức HTTP.
- Giao diện Web hiển thị biểu đồ nhiệt độ và độ ẩm trực quan theo thời gian thực.


### Firmware (ESP32)
- Ngôn ngữ/Framework: C/C++, Arduino IDE.
- Thư viện chính: `WiFi.h`, `HTTPClient.h`, `DHT.h`.
- **Tính năng cốt lõi:**
    * Đọc dữ liệu môi trường (nhiệt độ, độ ẩm) từ cảm biến.
    * Cơ chế tự động quản lý và kết nối lại WiFi khi mất tín hiệu (Auto-reconnect).
    * Đóng gói dữ liệu thô sang định dạng JSON để tối ưu hóa quá trình truyền tải mạng.

### Backend (Server)
- Công nghệ: Node.js.
- Thư viện sử dụng: `express`, `cors`, `body-parser`.
- **Chức năng chính:**
    * REST API: Cung cấp các đường dẫn để ESP32 gửi dữ liệu lên và Web lấy dữ liệu về.
    * Xử lý dữ liệu: Tiếp nhận và định dạng dữ liệu JSON từ cảm biến.
    * Kết nối: Cấu hình CORS để cho phép Frontend truy cập vào API.

### Frontend (Web Dashboard)
- Công nghệ: HTML5, CSS3, JavaScript).
* **Chức năng chính:**
    * Sử dụng JavaScript để gọi API từ Server và lấy dữ liệu cảm biến mới nhất.
    * Tự động đưa dữ liệu vào các cột hiển thị trên trang web mà không cần tải lại trang.
    * Sử dụng CSS để tạo hình, định dạng kích thước và màu sắc cho các cột dữ liệu, giúp việc theo dõi trở nên trực quan hơn.
    * Thiết kế đơn giản, tập trung vào việc hiển thị thông số nhiệt độ và độ ẩm rõ ràng.
---

## Yêu cầu phần cứng (Hardware Requirements)
* Board điều khiển: **ESP32 DevKit V1**
* Cảm biến: **DHT22**
* Phụ kiện: Dây cắm, Breadboard, cáp Micro USB.
