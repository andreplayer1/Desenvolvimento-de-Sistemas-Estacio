// 1. Crie dois arrays paralelos produtos/preços
let produtos = ['Laranja', 'Uva', 'Pêra', 'Maçã', 'Goiaba'];
let precos = [5, 7, 9, 6, 4];

console.log('PRODUTOS E VALORES.')
for(i = 0; i <= 4; i++){
    console.log(`${produtos[i]} - R$ ${precos[i]}`)
}
   
//2. Exiba na tela (via `console.log`) um produto (nome e preço), mostrando o nome e o preço do item na posição 0 dos arrays.
console.log(`Produto na posição 0 é:`);
console.log(`${produtos[0]} - R$ ${precos[0]}\n`);

//3. Utilize os seguintes métodos de array durante a execução do programa:  

//- push() → para adicionar um novo produto ao final da lista.
produtos.push('Banana');
precos.push(3);
posicao = produtos.indexOf('Banana');
console.log('Adicionei um produto ao final da lista');
console.log(`${produtos[produtos.indexOf('Banana')]} - R$ ${precos[posicao]}`);
console.log(produtos, precos);

//- pop() → para remover o último produto da lista.
produtos.pop()
precos.pop()
console.log('\nRemovi o ultimo produto do final da lista');
console.log(produtos, precos);

//- unshift() → para adicionar um produto no início da lista.
produtos.unshift('Jaca');
precos.unshift(15);
posicao = produtos.indexOf('Jaca');
console.log('\nAdicionei um produto ao inicio da lista');
console.log(`${produtos[produtos.indexOf('Jaca')]} R$ - ${precos[posicao]}`);
console.log(produtos, precos);

//- shift() → para remover o primeiro produto da lista.
produtos.shift()
precos.shift()
console.log('\nRemovi o primeiro produto da lista');
console.log(produtos, precos);

//- indexOf() → para localizar a posição de um produto específico dentro do array produtos.
console.log('\nMostrei a posição de um produto.')
console.log(`A posição de ${produtos[produtos.indexOf('Maçã')]} é ${produtos.indexOf('Maçã')} e o preço é R$ ${precos[produtos.indexOf('Maçã')]}`);

//ATENÇÃO: O produto é composto de seu nome e de seu preço.
//4. Após cada operação, mostre no console o estado atualizado dos arrays e o produto (nome e preço) correspondente ao índice escolhido.