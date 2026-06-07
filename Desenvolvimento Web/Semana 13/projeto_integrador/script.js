const campoBusca = document.querySelector("#campoBusca");
const head = document.querySelector("#head");
const resultado = document.querySelector("#result");

let consultar = (event) => {
    event.preventDefault();

    const termo = campoBusca.value;
    if (termo === "") {
        head.style.display = "none";
        resultado.innerHTML = "";
    } else {
        head.style.display = "";
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
                        <td> R$ ${produto.preco.toFixed(2)} </td>
                    </tr>
                `;
                });
                resultado.innerHTML = listaItensHTML;
            });
    }
}
campoBusca.addEventListener('input', consultar);