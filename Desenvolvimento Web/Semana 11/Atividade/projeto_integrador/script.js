const btn = document.getElementById("btnConsultar");
const resultadoArea = document.getElementById("resultado");

btn.addEventListener("click", () => {
    const categoria = document.getElementById("categoriaProduto").value;

    // Validação simples no lado cliente (Semana 7) [11, 12]
    if (!categoria) {
        alert("Por favor, insira uma categoria!");
        return;
    }

    // Uso moderno da Fetch API para chamada assíncrona (Semana 10/11) [7, 13]
    fetch(`servidor.php?categoria=${categoria}`)
        .then(response => response.json()) // Converte a resposta em objeto JS [14, 15]
        .then(dados => {
            resultadoArea.style.display = "block";

            if (dados.erro) {
                resultadoArea.innerHTML = `<p style="color:red">${dados.erro}</p>`;
            } else {

                let listaHtml = "";

                dados.forEach(produto => {
                    listaHtml += `
                        <div style="border-bottom: 1px solid #ccc; margin-bottom: 15px; paddin-bottom: 10px;">
                            <strong>ID:</strong> ${produto.id} <br>
                            <strong>Produto:</strong> ${produto.nome} <br>
                            <strong>Preço:</strong> R$ ${produto.preco.toFixed(2)} <br>
                            <strong>Disponível:</strong> ${produto.quantidade} un. <br>
                            <strong>Categoria:</strong> ${produto.categoria}
                        </div>
                    `;
                });

                // Pega todo o HTML acumulado e joga na tela de uma vez
                resultadoArea.innerHTML = listaHtml;
            }
        })
        .catch(erro => console.error("Erro na requisição:", erro));
});