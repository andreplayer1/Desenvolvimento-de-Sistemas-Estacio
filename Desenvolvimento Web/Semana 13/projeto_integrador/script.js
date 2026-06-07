const campoBusca = document.querySelector("#campoBusca");
const btnConsultar = document.querySelector("#btnConsultar");
const resultado = document.querySelector("#result");

let consultar = (event) => {
    event.preventDefault();

    const termo = campoBusca.value;
    console.log(termo);

    fetch(`servidor.php?busca=${termo}`)
        .then(response => {
            if (!response.ok) {
                console.log('Erro na requisição')
            }
            return response.json();
        })
        .then(dados => {
            let listaItensHTML = '';
            dados.forEach(produto => {
                listaItensHTML += `
                    <tr>
                        <td> ${produto.id} </td>
                        <td> ${produto.nome} </td>
                        <td> ${produto.categoria} </td>
                        <td> ${produto.preco} </td>
                    </tr>
                `;
            });
            resultado.innerHTML = listaItensHTML;
        });
}
btnConsultar.addEventListener('click', consultar);