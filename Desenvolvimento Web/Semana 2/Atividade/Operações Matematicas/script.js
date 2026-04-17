alert("Digite dois numeros a seguir para fazer algumas operações matemáticas.");
let number1 = Number(prompt("Digite o primeiro número:"));
let number2 = Number(prompt("Digite o segundo número:"));

let soma = number1 + number2;
let subtracao = number1 - number2;
let multiplicacao = number1 * number2;
let divisao = number1 / number2;
let resto = number1 % number2;
let potencia = number1 ** number2;

document.getElementById("Resultado").innerHTML = `Soma: ${number1} + ${number2} = ${soma} 
<br>Subtração: ${number1} - ${number2} = ${subtracao}<br>Multiplicação: ${number1} * ${number2} = ${multiplicacao}
<br>Divisão: ${number1} / ${number2} = ${divisao} <br>Resto: ${number1} % ${number2} = ${resto}
<br>Potência: ${number1} ** ${number2} = ${potencia}`;