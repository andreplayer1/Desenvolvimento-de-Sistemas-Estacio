let form = document.getElementById('formulario');
let entrada = document.getElementById('entrada');
let campo = document.getElementById('campo');
let botaoExcluir = document.getElementById('excluir');

let listaDeTarefas = [];

form.addEventListener('submit', (e) => {
    e.preventDefault();

    if (entrada.value != '') {
        listaDeTarefas.push(entrada.value);
        entrada.value = '';
        atualizarCampo();
    }
});

let atualizarCampo = () => {
    campo.innerHTML = '';

    for(let i = 0; i < listaDeTarefas.length; i++) {
        campo.innerHTML += `
        <li>
            <input type="checkbox" class="check-tarefa">
            <span>${listaDeTarefas[i]}</span>
        </li>
        `;
    }
}

botaoExcluir.addEventListener('click', () => {
    let caixinhas = document.querySelectorAll('.check-tarefa');
    let tarefasQueSobrarem = [];

    for(let i = 0; i < caixinhas.length; i++) {
        if(caixinhas[i].checked === false) {
            tarefasQueSobrarem.push(listaDeTarefas[i]);
        }
    }

    listaDeTarefas = tarefasQueSobrarem;
    atualizarCampo();
});