<script setup>
import { ref } from "vue";

let jogador1 = true;
let hasWinner = false;
let winner = "";

const buttons = ref([
  [
    { v: 0, t: "." },
    { v: 0, t: "." },
    { v: 0, t: "." },
  ],
  [
    { v: 0, t: "." },
    { v: 0, t: "." },
    { v: 0, t: "." },
  ],
  [
    { v: 0, t: "." },
    { v: 0, t: "." },
    { v: 0, t: "." },
  ],
]);

function reset() {
  jogador1 = true;
  hasWinner = false;
  winner = "";
  buttons.value = [
    [
      { v: 0, t: "." },
      { v: 0, t: "." },
      { v: 0, t: "." },
    ],
    [
      { v: 0, t: "." },
      { v: 0, t: "." },
      { v: 0, t: "." },
    ],
    [
      { v: 0, t: "." },
      { v: 0, t: "." },
      { v: 0, t: "." },
    ],
  ];
}

function changeBtn(line, column) {
  if (buttons.value[line][column].v == 0) {
    buttons.value[line][column].t = jogador1 ? "X" : "O";
    buttons.value[line][column].v = jogador1 ? 1 : -1;
    jogador1 = !jogador1;
    checkWinner();
  }
}

function checkWinner() {
  // horizontal
  buttons.value.forEach((across) => {
    if (across[0].v + across[1].v + across[2].v === 3) {
      hasWinner = true;
      winner = "jogador 1";
    } else if (across[0].v + across[1].v + across[2].v === -3) {
      hasWinner = true;
      winner = "jogador 2";
    }
  });
  // vertical
  [0, 1, 2].forEach((line) => {
    const value =
      buttons.value[0][line].v +
      buttons.value[1][line].v +
      buttons.value[2][line].v;
    if (value == 3) {
      hasWinner = true;
      winner = "jogador 1";
    } else if (value == -3) {
      hasWinner = true;
      winner = "jogador 2";
    }
  });
  // diagonal
  let diag =
    buttons.value[0][2].v + buttons.value[1][1].v + buttons.value[2][0].v;
  if (diag == 3) {
    hasWinner = true;
    winner = "jogador 1";
  } else if (diag == -3) {
    hasWinner = true;
    winner = "jogador 2";
  }

  diag = buttons.value[0][0].v + buttons.value[1][1].v + buttons.value[2][2].v;
  if (diag == 3) {
    hasWinner = true;
    winner = "jogador 1";
  } else if (diag == -3) {
    hasWinner = true;
    winner = "jogador 2";
  }
}
</script>

<template>
  <template v-for="(line, iline) in buttons" :key="iline">
    <button
      class="btn"
      v-for="(btn, ibtn) in line"
      :key="ibtn"
      @click="changeBtn(iline, ibtn)"
      :disabled="hasWinner"
    >
      {{ btn.t }}
    </button>
    <br />
  </template>
  <template v-if="hasWinner">
    <h1>{{ winner }} venceu!</h1>
    <button @click="reset">Resetar o jogo</button>
  </template>
</template>

<style>
.btn {
  height: 80px;
  width: 80px;
}
</style>
