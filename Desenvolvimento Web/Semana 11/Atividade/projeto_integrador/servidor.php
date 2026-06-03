<?php
// Define o cabeçalho para que o navegador entenda que a resposta é JSON [6]
header('Content-Type: application/json');

// Simulação de banco de dados (Semana 11 - Slide 3) [4]
$estoque = [
    1 => ["nome" => "Notebook Pro", "preco" => 5500.00, "quantidade" => 5, "categoria" => "Computadores"],
    2 => ["nome" => "Monitor UltraWide", "preco" => 1200.00, "quantidade" => 12, "categoria" => "Monitores"],
    3 => ["nome" => "Teclado Mecânico", "preco" => 350.00, "quantidade" => 20, "categoria" => "Perifericos"],
    4 => ["nome" => "Gabinete Montech King 95", "preco" => 850.00, "quantidade" => 8, "categoria" => "Componentes"],
    5 => ["nome" => "Placa de Vídeo RTX 5060", "preco" => 2100.00, "quantidade" => 15, "categoria" => "Componentes"],
    6 => ["nome" => "Suporte Articulado Zinnia Nimbo", "preco" => 160.00, "quantidade" => 30, "categoria" => "Perifericos"],
    7 => ["nome" => "Mouse Gamer Sem Fio", "preco" => 250.00, "quantidade" => 25, "categoria" => "Perifericos"],
    8 => ["nome" => "Headset Gamer 7.1", "preco" => 400.00, "quantidade" => 18, "categoria" => "Perifericos"],
    9 => ["nome" => "Placa Mãe B550", "preco" => 900.00, "quantidade" => 10, "categoria" => "Componentes"],
    10 => ["nome" => "Memória RAM 16GB DDR5", "preco" => 450.00, "quantidade" => 40, "categoria" => "Componentes"]
];

// Captura o parâmetro 'categoria' enviado via método GET (Slide 4) [7]
$categoriaBuscada = $_GET['categoria'] ?? null;

// Array vazio para guardar os produtos encontrados.
$resultados = [];

// Aqui diz se categoria foi buscada na requisição...
if ($categoriaBuscada) {

    //Percorremos o estoque item por item
    foreach ($estoque as $id => $produto) {

        // Verifica se a categoria do produto atual é igual a que foi buscada.
        // Convertemos tudo para minusculo para evitar erros.
        if (strtolower($produto["categoria"]) === strtolower($categoriaBuscada)) {

            $produto["id"] = $id; // inclui a id original dentro dos dados do produto
            $resultados[] = $produto; // adiciona o produto na nossa lista de resultados
        }
    }
    // Verifica se a lista de resultados não está vazia
    if (count($resultados) > 0) {
        // Envia a lista encontrada
        echo json_encode($resultados);
    } else {
        // Envia mensagem se a categoria existe, mas não tem produtos
        echo json_encode(["erro" => "Nenhum produto localizado na categoria."]);
    }
} else {
    echo json_encode(["erro" => "Categoria não informada na busca."]);
}