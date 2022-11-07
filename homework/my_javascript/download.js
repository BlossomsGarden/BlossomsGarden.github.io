function downloadaudio(filePath) {
    fetch(filePath).then(res => res.blob()).then(blob => {
    const a = document.createElement('a');
    document.body.appendChild(a)
    a.style.display = 'none'
    const url = window.URL.createObjectURL(blob);
    a.href = url;
    a.download = 'xxxx.mp3';
    a.click();
    document.body.removeChild(a)
    window.URL.revokeObjectURL(url);
    });
}

function download() {
    this.downloadMp3('');
}