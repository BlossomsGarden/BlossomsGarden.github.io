//与浮动局部播放器相关的函数

//querySelector()方法：https://www.runoob.com/jsref/met-document-queryselector.html
//addEventListener()方法：https://blog.csdn.net/handsomeAndHero/article/details/125315491
///////////上滑显示音乐播放器
//由于点击取消时也会触发该函数，需要注意一下（这里使用fold判断）
const musicPlayerSection = document.querySelector('.music-player-section');
var fold=false;
musicPlayerSection.addEventListener('click', function(){
    console.log("调用显示函数！");
    if(!fold){
        console.log("播放器显现！");
        musicPlayerSection.classList.add('active');
    }
    else{
        fold=false;         //折叠完一次之后置false恢复初始值，不然下次拉不出来了
    }
})


///////////收起音乐播放器
const backToHomeBtn = document.querySelector('.music-player-section .backbtn');
backToHomeBtn.addEventListener('click', () => {
    console.log("播放器消失！");
    fold=true;      //读取到取消键点击
    musicPlayerSection.classList.remove('active');  //不仅自己的收起来，
    playlistSection.classList.remove('active');     //侧边栏如果有打开，也收起来，
    volumeBtn.classList.remove('active');
    volumeSlider.classList.remove('active');        //音量键没关，也收起来！

})



///////////play/pause按钮点击
const playBtn = document.querySelector('i.fa-play');
const pauseBtn = document.querySelector('i.fa-pause');
playBtn.addEventListener('click', () => {
    music.play();
    playBtn.classList.remove('active');
    pauseBtn.classList.add('active');
    fold=true;      //若播放器是浮动状态，别上拉
})

pauseBtn.addEventListener('click', () => {
    music.pause();
    pauseBtn.classList.remove('active');
    playBtn.classList.add('active');
    fold=true;      //若播放器是浮动状态，别上拉
})


///////////下一曲按钮点击
const forwardBtn = document.querySelector('i.fa-forward');
forwardBtn.addEventListener('click', () => {
    if(currentMusic >= songs.length - 1){
        currentMusic = 0;
    } else{
        currentMusic++;
    }
    setMusic(currentMusic);
    playBtn.click();
    fold=true;      //若播放器是浮动状态，别上拉
})


///////////上一曲按钮点击
const backwardBtn = document.querySelector('i.fa-backward');
backwardBtn.addEventListener('click', () => {
    if(currentMusic <= 0){
        currentMusic = songs.length - 1;
    } else{
        currentMusic--;
    }
    setMusic(currentMusic);
    playBtn.click();
    fold=true;      //若播放器是浮动状态，别上拉
})






//与整体显示的播放器相关的函数

///////////从头播放按钮
const remakeBtn = document.querySelector('span.fa-redo');
remakeBtn.addEventListener('click', () => {
    console.log("从头播放！");
    setMusic(currentMusic);
    playBtn.click();
})


///////////单曲循环\顺序播放按钮
const cycleBtn = document.querySelector('i.fa-cycle');
const inorderBtn = document.querySelector('i.fa-inorder');
cycleBtn.addEventListener('click', () => {
    console.log("开启循环！");
    cycleBtn.classList.remove('active');
    inorderBtn.classList.add('active');
    fold=true;      //若播放器是浮动状态，别上拉
})
inorderBtn.addEventListener('click', () => {
    console.log("关闭循环！");
    cycleBtn.classList.add('active');
    inorderBtn.classList.remove('active');
    fold=true;      //若播放器是浮动状态，别上拉
})


///////////音量按钮
const volumeBtn = document.querySelector('span.fa-volume-up');
const volumeSlider = document.querySelector('.volume-slider');
volumeBtn.addEventListener('click', () => {
    console.log("点击音量按钮！");
    volumeBtn.classList.toggle('active');
    volumeSlider.classList.toggle('active');
})

volumeSlider.addEventListener('input', () => {
    music.volume = volumeSlider.value;
})


///////////播放列表弹出
const playlistSection = document.querySelector('.playlist');
const navBtn = document.querySelector('.music-player-section .playlistbtn');
navBtn.addEventListener('click', () => {
    console.log("播放器列表弹出！");
    playlistSection.classList.add('active');
})


///////////从播放列表返回到音乐播放器
const backToMusicPlayer = document.querySelector('.playlist .playlist-backbtn');
backToMusicPlayer.addEventListener('click', () => {
    console.log("播放列表消失！");
    playlistSection.classList.remove('active');
})



///////////播放列表选歌
queue.forEach((item, i) => {

    if(i < songs.length)
        item.querySelector('.name').innerText = songs[i].name;

    //console.log(item.querySelector('.name'));
    
    item.addEventListener('click', () => {
        setMusic(i);
        playBtn.click();
        backToMusicPlayer.click();
    })
})
