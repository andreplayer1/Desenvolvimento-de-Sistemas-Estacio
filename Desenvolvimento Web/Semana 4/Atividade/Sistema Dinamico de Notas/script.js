let nota;
let soma = 0;
let contador = 0;

nota = parseFloat(prompt("Digite a nota do aluno (ou -1 para encerrar):"));
while (nota !== -1) {
    soma += nota;

    contador++;

    nota = parseFloat(prompt("Digite a próxima nota (ou -1 para encerrar):"));
}

if (contador > 0) {
    let media = soma/contador;
    alert(`A média da turma é: ${media.toFixed(2)}`);
    alert(`Você adicionou ${contador} notas.`)
} else {
    alert("Nenhuma nota foi digitada.");
}