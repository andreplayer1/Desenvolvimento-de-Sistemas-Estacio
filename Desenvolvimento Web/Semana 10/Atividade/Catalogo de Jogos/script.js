// 1. O SEU CÓDIGO ORIGINAL (CRUD)
let catalogoDeJogos = [
    { id: 1, titulo: "Horizon Zero Dawn", genero: "Aventura", estado: "Concluído" },
    { id: 2, titulo: "Monster Hunter World", genero: "RPG", estado: "A jogar" },
    { id: 3, titulo: "Final Fantasy XVI", genero: "JRGP Turno", estado: "A jogar" },
    { id: 4, titulo: "Clair Obscur", genero: "RPG Turno", estado: "Repetindo" },
    { id: 5, titulo: "Baldur's Gate", genero: "RPG", estado: "A jogar" }
];

let adicionarJogo = (titulo, genero, estado) => {
    let novoId = catalogoDeJogos.length > 0 ? catalogoDeJogos[catalogoDeJogos.length - 1].id + 1 : 1;
    catalogoDeJogos.push({ id: novoId, titulo: titulo, genero: genero, estado: estado });
}

let atualizarEstado = (id, novoEstado) => {
    for (let i = 0; i < catalogoDeJogos.length; i++) {
        if (catalogoDeJogos[i].id === id) {
            catalogoDeJogos[i].estado = novoEstado;
            break;
        }
    }
}

let excluirJogo = (idParaExcluir) => {
    catalogoDeJogos = catalogoDeJogos.filter(jogo => jogo.id !== idParaExcluir);
}

// Executando suas operações antes de renderizar
adicionarJogo("Dragon Ball: Sparking Zero", "Luta", "Na fila");
adicionarJogo("Sifu", "Luta", "A jogar");
atualizarEstado(3, "Jogando");
excluirJogo(5);

// 2. SIMULANDO A REQUISIÇÃO (Para cumprir o laboratório)
function simularFetchAPI() {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve(catalogoDeJogos);
        }, 1200); // 1.2 segundos de atraso fingindo ser a internet
    });
}

// 3. INJEÇÃO NO DOM (Renderizando a tela)
const btnCarregar = document.getElementById('btnCarregar');
const listaJogos = document.getElementById('listaJogos');

btnCarregar.addEventListener('click', async () => {
    // Estado de Loading (Feedback pro usuário!)
    btnCarregar.innerText = "Sincronizando com a nuvem...";
    btnCarregar.disabled = true;

    // O 'await' segura o código aqui até os dados chegarem
    const dados = await simularFetchAPI();

    // Limpa a tela
    listaJogos.innerHTML = "";

    // O seu antigo Console.log agora cria elementos visuais
    for (let i = 0; i < dados.length; i++) {
        const li = document.createElement('li');
        li.innerHTML = `
            <div>
                <strong>${dados[i].titulo}</strong> <br>
                <span class="genero">${dados[i].genero}</span>
            </div>
            <span class="tag">${dados[i].estado}</span>
        `;
        listaJogos.appendChild(li);
    }

    btnCarregar.innerText = "Biblioteca Atualizada!";
});