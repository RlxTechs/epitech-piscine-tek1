const canvas = document.getElementById("game");
const ctx = canvas.getContext("2d");

const scoreEl = document.getElementById("score");
const livesEl = document.getElementById("lives");

const state = {
  player: { x: 420, y: 250, size: 34, speed: 5 },
  coin: { x: 120, y: 120, size: 20 },
  enemy: { x: 80, y: 80, size: 32, dx: 3, dy: 2 },
  keys: {},
  score: 0,
  lives: 3,
  running: true
};

function clamp(value, min, max) {
  return Math.max(min, Math.min(max, value));
}

function rectsOverlap(a, b) {
  return !(
    a.x + a.size < b.x ||
    b.x + b.size < a.x ||
    a.y + a.size < b.y ||
    b.y + b.size < a.y
  );
}

function spawnCoin() {
  state.coin.x = 40 + Math.floor(Math.random() * (canvas.width - 100));
  state.coin.y = 60 + Math.floor(Math.random() * (canvas.height - 120));
}

function updatePlayer() {
  const p = state.player;

  if (state.keys.ArrowLeft || state.keys.a) p.x -= p.speed;
  if (state.keys.ArrowRight || state.keys.d) p.x += p.speed;
  if (state.keys.ArrowUp || state.keys.w) p.y -= p.speed;
  if (state.keys.ArrowDown || state.keys.s) p.y += p.speed;

  p.x = clamp(p.x, 0, canvas.width - p.size);
  p.y = clamp(p.y, 0, canvas.height - p.size);

  if (rectsOverlap(p, state.coin)) {
    state.score += 10;
    spawnCoin();
  }
}

function updateEnemy() {
  const e = state.enemy;

  e.x += e.dx;
  e.y += e.dy;

  if (e.x < 0 || e.x + e.size > canvas.width) e.dx *= -1;
  if (e.y < 0 || e.y + e.size > canvas.height) e.dy *= -1;

  if (rectsOverlap(state.player, e)) {
    state.lives -= 1;
    state.player.x = canvas.width / 2;
    state.player.y = canvas.height / 2;

    if (state.lives <= 0) {
      state.running = false;
    }
  }
}

function draw() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  ctx.fillStyle = "#0f172a";
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  ctx.fillStyle = "#22c55e";
  ctx.fillRect(state.player.x, state.player.y, state.player.size, state.player.size);

  ctx.fillStyle = "#facc15";
  ctx.beginPath();
  ctx.arc(
    state.coin.x + state.coin.size / 2,
    state.coin.y + state.coin.size / 2,
    state.coin.size / 2,
    0,
    Math.PI * 2
  );
  ctx.fill();

  ctx.fillStyle = "#ef4444";
  ctx.fillRect(state.enemy.x, state.enemy.y, state.enemy.size, state.enemy.size);

  if (!state.running) {
    ctx.fillStyle = "white";
    ctx.font = "48px Arial";
    ctx.fillText("GAME OVER", canvas.width / 2 - 140, canvas.height / 2);
  }

  scoreEl.textContent = `Score: ${state.score}`;
  livesEl.textContent = `Lives: ${state.lives}`;
}

function loop() {
  if (state.running) {
    updatePlayer();
    updateEnemy();
  }

  draw();
  requestAnimationFrame(loop);
}

window.addEventListener("keydown", (event) => {
  state.keys[event.key] = true;
});

window.addEventListener("keyup", (event) => {
  state.keys[event.key] = false;
});

spawnCoin();
loop();
