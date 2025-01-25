const text = "WELCOME TO PN NGUYEN :))";
const header = document.querySelector('.header');

let index = 0;
function typeEffect() {
  header.textContent = text.slice(0, index); // Cắt từng phần của chữ
  index++;

  if (index > text.length) {
    index = 1; // Reset lại từ đầu
  }

  setTimeout(typeEffect, 120); 
}

typeEffect();
