//
// Created by Gabriel Rocco on 23/10/2019.
//

#include "cartao_amigo.h"
//-----------------------
int Hora::getHora() const {
    return hora;
}

void Hora::setHora(int hora) {
    Hora::hora = hora;
}

int Hora::getMinutos() const {
    return minutos;
}

void Hora::setMinutos(int minutos) {
    Hora::minutos = minutos;
}

const string &Local::getRua() const {
    return rua;
}

void Local::setRua(const string &rua) {
    Local::rua = rua;
}

int Local::getCep() const {
    return cep;
}

void Local::setCep(int cep) {
    Local::cep = cep;
}

const Local &Instituicao::getLocalizacao() const {
    return localizacao;
}

void Instituicao::setLocalizacao(const Local &localizacao) {
    Instituicao::localizacao = localizacao;
}

bool Instituicao::isAderente() const {
    return aderente;
}

void Instituicao::setAderente(bool aderente) {
    Instituicao::aderente = aderente;
}

int Cliente::getTipoAssinatura() const {
    return tipo_assinatura;
}

void Cliente::setTipoAssinatura(int tipoAssinatura) {
    tipo_assinatura = tipoAssinatura;
}

const string &Cliente::getNome() const {
    return nome;
}

void Cliente::setNome(const string &nome) {
    Cliente::nome = nome;
}

const Date &Cliente::getNascimento() const {
    return nascimento;
}

void Cliente::setNascimento(const Date &nascimento) {
    Cliente::nascimento = nascimento;
}

const Local &Cliente::getMorada() const {
    return morada;
}

void Cliente::setMorada(const Local &morada) {
    Cliente::morada = morada;
}

int Cliente::getContacto() const {
    return contacto;
}

void Cliente::setContacto(int contacto) {
    Cliente::contacto = contacto;
}

const Date &Cliente::getAquisicaoCartao() const {
    return aquisicao_cartao;
}

void Cliente::setAquisicaoCartao(const Date &aquisicaoCartao) {
    aquisicao_cartao = aquisicaoCartao;
}

int Cliente::getNif() const {
    return nif;
}

void Cliente::setNif(int nif) {
    Cliente::nif = nif;
}

bool Evento::isAceitaDescontoCartaoAmigo() const {
    return aceita_desconto_cartao_amigo;
}

void Evento::setAceitaDescontoCartaoAmigo(bool aceitaDescontoCartaoAmigo) {
    aceita_desconto_cartao_amigo = aceitaDescontoCartaoAmigo;
}

const Local &Evento::getLocalizacao() const {
    return localizacao;
}

void Evento::setLocalizacao(const Local &localizacao) {
    Evento::localizacao = localizacao;
}

int Evento::getBilhetesTotais() const {
    return bilhetes_totais;
}

void Evento::setBilhetesTotais(int bilhetesTotais) {
    bilhetes_totais = bilhetesTotais;
}

int Evento::getBilhetesReservados() const {
    return bilhetes_reservados;
}

void Evento::setBilhetesReservados(int bilhetesReservados) {
    bilhetes_reservados = bilhetesReservados;
}

int Evento::getBilhetesDisponiveis() const {
    return bilhetes_disponiveis;
}

void Evento::setBilhetesDisponiveis(int bilhetesDisponiveis) {
    bilhetes_disponiveis = bilhetesDisponiveis;
}

int Evento::getPorcentagemDisponivel() const {
    return porcentagem_disponivel;
}

void Evento::setPorcentagemDisponivel(int porcentagemDisponivel) {
    porcentagem_disponivel = porcentagemDisponivel;
}



