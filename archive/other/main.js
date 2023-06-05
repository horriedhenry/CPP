const btn = document.getElementById('btn');
let count = 0;

function render() {
    btn.innerText = `Count: ${count}`;
}

btn.addEventListener('click', () => {
    if (count < 10) {
        count += 1;
        render();
    }
});
