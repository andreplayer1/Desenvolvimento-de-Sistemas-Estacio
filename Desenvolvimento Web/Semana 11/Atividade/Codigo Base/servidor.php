<?php
// Define o cabeçalho para que o navegador entenda que a resposta é JSON [6]
header('Content-Type: application/json');

// Simulação de banco de dados (Semana 11 - Slide 3) [4]
$estoque = [
    1 => ["nome" => "Notebook Pro", "preco" => 5500.00, "quantidade" => 5],
    2 => ["nome" => "Monitor UltraWide", "preco" => 1200.00, "quantidade" => 12],
    3 => ["nome" => "Teclado Mecânico", "preco" => 350.00, "quantidade" => 20]
];

// Captura o parâmetro 'id' enviado via método GET (Slide 4) [7]
$id = $_GET['id'] ?? null;

if ($id && isset($estoque[$id])) {
    // Converte o array PHP em uma string JSON para o navegador [4, 5]
    echo json_encode($estoque[$id]);
} else {
    // Retorna uma mensagem de erro caso o item não exista
    echo json_encode(["erro" => "Produto não localizado no estoque."]);
}
?>