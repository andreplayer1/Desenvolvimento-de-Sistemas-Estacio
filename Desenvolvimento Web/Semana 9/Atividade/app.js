let catalogoDeJogos = [
    {
        id: 1,
        titulo: "Horizon Zero Dawn",
        genero: "Aventura",
        estado: "Concluído"
    },
    {
        id: 2,
        titulo: "Monster Hunter World",
        genero: "RPG",
        estado: "A jogar"
    },
    {
        id: 3,
        titulo: "Final Fantasy XVI",
        genero: "JRGP Turno",
        estado: "A jogar"
    },
    {
        id: 4,
        titulo: "Clair Obscur",
        genero: "RPG Turno",
        estado: "Repetindo"
    },
    {
        id: 5,
        titulo: "Baldur's Gate",
        genero: "RPG",
        estado: "A jogar"
    },
]

let adicionarJogo = (titulo, genero, estado) => {

    let novoId = catalogoDeJogos.length + 1;

    let novoJogo =
    {
        id: novoId,
        titulo: titulo,
        genero: genero,
        estado: estado
    };

    catalogoDeJogos.push(novoJogo);
}

let atualizarEstado = (id, novoEstado) => {
    let encontrouJogo = false;

    for (let i = 0; i < catalogoDeJogos.length; i++) {

        if (catalogoDeJogos[i].id === id) {
            catalogoDeJogos[i].estado = novoEstado;
            encontrouJogo = true;
            break;
        }
    }

    if(encontrouJogo === false){
        console.log("Erro: ID Inválido ou não encontrado.");
    }
}

let excluirJogo = (idParaExcluir) => {
    catalogoDeJogos = catalogoDeJogos.filter(jogo => jogo.id !== idParaExcluir);
}

adicionarJogo("Dragon Ball: Sparking Zero", "Luta", "Na fila");

adicionarJogo("Sifu", "Luta", "A jogar");

atualizarEstado(3, "Jogando");

excluirJogo(5);

for (let i = 0; i < catalogoDeJogos.length; i++) {
    console.log(`O jogo é ${catalogoDeJogos[i].titulo} é do gênero ${catalogoDeJogos[i].genero} e seu estado atual é: ${catalogoDeJogos[i].estado}`)
}