let dados = [
    { "nome": "Ana" },
    { "nome": "Carlos" }
]

let laco = () => {
    for (let i = 0; i < dados.length; i++) {
        console.log(dados[i].nome)
    }
}

let exibir = () => {
    let container = document.getElementById("container");
    for (let i = 0; i < dados.length; i++) {
        container.innerHTML += `<li>Nome: ${dados[i].nome}</li>`
    }
}

exibir();